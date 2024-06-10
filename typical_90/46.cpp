/**
 * author:  Kaoru
 * created: 11.06.2024 00:10:28
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
    int N;
    cin >> N;
    vi A(N), B(N),  C(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];
    rep(i, N) cin >> C[i];
    rep(i, N){
        A[i] = A[i] % 46;
        B[i] = B[i] % 46;
        C[i] = C[i] % 46;
    }
    vi cntA(46), cntB(46), cntC(46);
    rep(i, N){
        cntA[A[i]]++;
        cntB[B[i]]++;
        cntC[C[i]]++;
    }
    ll ans = 0;
    rep(i, 46){
        rep(j, 46){
            rep(k, 46){
                if((i+j+k) % 46 == 0){
                    ans += (ll)cntA[i] * cntB[j] * cntC[k];
                }
            }
        }
    }
    print(ans);
    return 0;
}