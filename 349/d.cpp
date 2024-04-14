#include <bits/stdc++.h>

using namespace std;

#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif

using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using vl = vector<long>;
using vll = vector<long long>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vvll = vector<vll>;
using vs = vector<string>;
using pii = pair<int, int>;

#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)

#define pb push_back
#define YESNO(bool) if(bool){cout<<"YES"<<"\n";}else{cout<<"NO"<<"\n";}
#define yesno(bool) if(bool){cout<<"yes"<<"\n";}else{cout<<"no"<<"\n";}
#define YesNo(bool) if(bool){cout<<"Yes"<<"\n";}else{cout<<"No"<<"\n";}

template <typename T> inline void print(const vector<T>& v, string s = " "){rep(i, v.size()) cout << v[i] << (i != (ll)v.size() - 1 ? s : "\n");}
template <typename T, typename S> inline void print(const pair<T, S>& p){cout << p.first << " " << p.second << "\n";}
template <typename T> inline void print(const T& x) {cout << x << "\n";}
template <typename T, typename S> inline void print(const vector<pair<T, S>>& v){for (auto&& p : v) print(p);}

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void enumerate_tic_tac_toe(vector<vector<char>>& board, int row, int col, char player) {
    // Base case: if the current cell is already occupied or the board is full
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != '.') {
        return;
    }

    // Place the player's mark in the current cell
    board[row][col] = player;

    // Check if the current board configuration is a valid game state
    bool valid_state = true;
    int row_count[3] = {0}; // Count marks in each row
    int col_count[3] = {0}; // Count marks in each column
    int diag_count[2] = {0}; // Count marks in each diagonal

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == player) {
                ++row_count[i];
                ++col_count[j];
                if (i == j) {
                    ++diag_count[0];
                }
                if (i + j == 2) {
                    ++diag_count[1];
                }
            }
        }
    }

    // Check if any row, column, or diagonal has 3 marks of the same player
    for (int i = 0; i < 3; ++i) {
        if (row_count[i] == 3 || col_count[i] == 3) {
            valid_state = false;
            break;
        }
    }

    if (diag_count[0] == 3 || diag_count[1] == 3) {
        valid_state = false;
    }

    // If the current state is valid, print the board
    if (valid_state) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // Recursively enumerate all possible next moves
    enumerate_tic_tac_toe(board, row + 1, col, (player == 'X') ? 'O' : 'X'); // Next row
    enumerate_tic_tac_toe(board, row, col + 1, (player == 'X') ? 'O' : 'X'); // Next column

    // Backtrack: reset the current cell to empty for other possible moves
    board[row][col] = '.';
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, '.')); // Initialize the board with empty cells
    rep(i, 3) {
        rep(j, 3) {
            enumerate_tic_tac_toe(board, i, j, 'X'); // Start with 'X' as the first player
        }
    }
    return 0;
}
