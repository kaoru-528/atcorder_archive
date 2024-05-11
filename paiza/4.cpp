/**
 * author:  Kaoru
 * created: 11.04.2024 12:01:50
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

int main()
{
    ll N;
    cin >> N;
    vll L(N), R(N);
    L[0] = 0;
    R[0] = 0;
    vll B ={0};
    for(int i = 1; i <= N; i++) cin >> L[i] >> R[i];
    ll Max = 0;
    B.pb(0);
    for(int i = 1; i <= N; i++){
        B[L[i]] += 1;
        B[R[i]+1] -= 1;
        Max = max(Max, R[i]);
    }
    vll dp(Max+2);
    dp.pb(0);
    for(int i = 1; i <= Max+1; i++){
        if(i == Max+1){
            dp[i] = 0;
        }
        else{
            dp[i] = dp[i-1] + B[i];
        }
    }
    ll count;
    ll ans = 0;
    for(int i = 1; i <= Max+1; i++){
        if(dp[i] != 0) count++;
        else if(dp[i] == 0){
            ans = max(ans, count);
            count = 0;
        }
    }
    print(dp);
    return 0;
}