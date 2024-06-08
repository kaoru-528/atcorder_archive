/**
 * author:  Kaoru
 * created: 08.06.2024 20:47:24
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

vector<vector<char>> func(int N, vector<vector<char>> A){
    int large_size = pow(3, N);
    vector<vector<char>> ans(large_size, vector<char>(large_size));
    rep(i, large_size) {
        rep(j, large_size) {
            if((i >= pow(3, N-1) && i < large_size - pow(3, N-1)) && (j >= pow(3, N-1) && j < large_size - pow(3, N-1))){
                // print(i);
                ans[i][j] = '.';
            }
            else{
                ans[i][j] = A[i % (int)pow(3, N-1)][j % (int)pow(3, N-1)];
            }
        }
    }
    return ans;
}

int main()
{
    int N;
    cin >> N;
    vector<vector<char>> A(pow(3, N), vector<char>(pow(3, N), '.'));

    for(int i = 0; i <= N; i++){
        if(i == 0){
            A[0][0] = '#';
        }
        else if(i == 1){
            A  = {{'#', '#', '#'}, {'#', '.', '#'}, {'#', '#', '#'}};
        }
        else{
            A = func(i, A);
        }
    }
    int large_size = pow(3, N);
    rep(i, large_size) {
        rep(j, large_size) {
            cout << A[i][j];
        }
        cout << '\n';
    }

    return 0;
}
