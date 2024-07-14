/**
 * author:  Kaoru
 * created: 13.07.2024 20:49:19
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

bool findZeroSum(vll& L, vll& R, vll& ans, ll current_sum, ll idx) {
    if (idx == L.size()) {
        return current_sum == 0;
    }

    for (int num = L[idx]; num <= R[idx]; ++num) {
        ans[idx] = num;
        if (findZeroSum(L, R, ans, current_sum + num, idx + 1)) {
            return true;
        }
    }

    return false;
}

int main()
{
    ll N;
    cin >> N;
    vll L(N);
    vll R(N);
    ll sum_L = 0;
    ll sum_R = 0;
    rep(i, N){
        cin >> L[i] >> R[i];
        sum_L += L[i];
        sum_R += R[i];
    }
    if(sum_L <= 0 && sum_R >= 0){
        print("Yes");

    }
    else{
        print("No");
        return 0;
    }
    vll ans(N,0);
    if(findZeroSum(L, R, ans, 0, 0)){
        print(ans);
    }
    // else{
    //     print("No");
    // }

    // ll tmp = 0;
    // vll ans;
    // rep(i, N){
    //     if(L[i] <= tmp && R[i] >= tmp){
    //        ans.pb(tmp);
    //         tmp = 0;
    //     }
    //     else if(L[i] > tmp){
    //         ans.pb(L[i]);
    //         tmp = tmp-L[i];
    //     }
    //     else{
    //         ans.pb(R[i]);
    //         tmp = tmp-R[i];
    //     }
    //     if(i == N-1 && tmp != 0){
    //         rep(j, N){
    //             if(L[j] <= tmp && R[j] >= tmp){
    //                 ans[j] = tmp;
    //                 break;
    //             }
    //             else if(L[j] > tmp){
    //                 ans[j] = L[j];
    //                 tmp = tmp-L[j];
    //             }
    //             else{
    //                 ans[j] = R[j];
    //                 tmp = tmp-R[j];
    //             }
    //         }
    //     }
    // }
    // print(ans);
    return 0;
}