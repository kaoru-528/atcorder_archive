/**
 * author:  Kaoru
 * created: 08.04.2024 18:29:25
 **/

#include <bits/stdc++.h>

using namespace std;
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
    int H, W;
    cin >> H >> W;

    vvi A(H, vi(W));
    vvi B(H, vi(W));
    rep(i, H) rep(j, W) cin >> A[i][j];
    rep(i, H) rep(j, W) cin >> B[i][j];

    vvi ans(2*H-1, vi(2*W-1));
    rep(i, 2*H-1){
        rep(j, 2*W-1){
            ans[i][j] = (A[(i+1)/2][(j+1)/2] + B[(i)/2][(j)/2])/2;
        }
    }
    rep(i, 2*H-1){
        rep(j, 2*W-1){
            if(j != 2*W-2) cout << ans[i][j] << " ";
            else cout << ans[i][j];
        }
        if(i != 2*H-2) cout << "\n";
        else cout << endl;
    }

    return 0;
}