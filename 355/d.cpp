/**
 * author:  Kaoru
 * created: 25.05.2024 20:50:11
 **/

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

int main() {
    int N, T;
    cin >> N >> T;
    vvi grid(N, vi(N));
    map<int, pair<int, int>> position;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int value = N * i + j + 1;
            grid[i][j] = value;
            position[value] = {i, j};
        }
    }
    
    vi row_count(N, 0), col_count(N, 0);
    int diag1_count = 0, diag2_count = 0;
    
    for (int turn = 1; turn <= T; ++turn) {
        int Ai;
        cin >> Ai;
        pair<int, int> pos = position[Ai];
        int i = pos.first, j = pos.second;
        row_count[i]++;
        col_count[j]++;
        if (i == j) {
            diag1_count++;
        }
        if (i + j == N - 1) {
            diag2_count++;
        }
        if (row_count[i] == N || col_count[j] == N || diag1_count == N || diag2_count == N) {
            cout << turn << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}
