/**
 * author:  Kaoru
 * created: 06.07.2024 20:56:02
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
    ll N, K;
    cin >> N >> K;
    vll A(N);
    set<ll> s;
    rep(i, N) cin >> A[i];
    sort(all(A));
    // if(K%2 == 0){
    //     print(A);
    //     ll tmp = K/2;
    //     rep(i,tmp, N-tmp){
    //         s.insert(A[i]);
    //     }
    //     for(auto x : s) {
    //      cout << x << "\n";
    // }
    //     print(*s.rbegin()-*s.begin());
    // }
    // else{
    //     ll tmp = K/2;
    //     set<ll> s_1;
    //     set<ll> s_2;
    //     ll ans = 0;
    //     rep(i,tmp+1, N-tmp-1){
    //         s_1.insert(A[i]);
    //         s_2.insert(A[i]);
    //     }
    //     s_1.insert(A[tmp]);
    //     s_2.insert(A[N-tmp-1]);
    //     ans = min(*s_1.rbegin()-*s_1.begin(), *s_2.rbegin()-*s_2.begin());
    //     print(ans);
    // }
    ll ans = A[N-1] - A[0];
    rep(i, K+1){
        ans = min(ans, (A[N-(K-i+1)]-A[0+i]));
    }
    print(ans);
    return 0;
}