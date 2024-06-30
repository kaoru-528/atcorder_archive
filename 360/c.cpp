/**
 * author:  Kaoru
 * created: 30.06.2024 20:56:16
 **/

#include <bits/stdc++.h>

using namespace std;

#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif

using ull = unsigned long long;
using ll = long long;
using vi = vector<ll>;
using vl = vector<long>;
using vll = vector<long long>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vvll = vector<vll>;
using vs = vector<string>;
using pii = pair<ll, ll>;

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

// int main()
// {
//     ll N;
//     cin >> N;
//     vi A(N);
//     vi W(N);
//     map<ll, ll> mpp;
//     rep(i, N) cin >> A[i];
//     rep(i, N) cin >> W[i];
//     vvi dp(N, vi(1, 0));
//     rep(i, N){
//         dp[A[i]-1].pb(i);
//         mpp[W[i]] = A[i]-1;
//     }
//     ll cnt = 0;
//     vi num(N);
//     rep(i,N){
//         if(dp[i].size() == 1){
//             cnt++;
//         }
//         // print(dp[A[i]-1].size()-1);
//         num[A[i]-1] = dp[A[i]-1].size()-1;
//     }
//     // print(num);
//     sort(all(W));
//     ll cost = 0;
//     rep(i, N){
//         if(num[mpp[W[i]]] >= 2){
//             cost += W[i];
//             // print(mp[W[i]]);
//             num[mpp[W[i]]]--;
//             cnt--;
//         }
//         // print(num);
//         if(cnt == 0) break;
//     }
//     print(cost);
//     return 0;
// }

int main(){
    ll N;
    cin >> N;
    vll A(N), W(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> W[i];
    vvi dp(N, vi(1, 0));
    ll sum = 0;
    rep(i, N){
        sum += W[i];
        dp[A[i]-1].pb(W[i]);
    }
    ll tmp = 0;
    rep(i, N){
        sort(all(dp[i]));
        tmp += dp[i][dp[i].size()-1];
    }
    print(sum-tmp);
    return 0;
}