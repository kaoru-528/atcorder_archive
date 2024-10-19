/**
 * author:  Kaoru
 * created: 19.10.2024 20:57:33
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

// int main()
// {
//     int N, Q;
//     cin >> N >> Q;
//     int L = 1, R = 2;
//     int ans = 0;
//     for(int i = 0; i < Q; i++){
//         char s;
//         int n;
//         cin >> s >> n;
//         if(s == 'L'){
//             int l = L;
//             if(l != n){
//                 while(l == n){
//                     l++;
//                     if(l == N+1){
//                         l = 1;
//                     }
//                     if(l = R){
//                         break;
//                     }
//                 }
//                 if(l == n){
//                     ans += abs(n-l);
//                 }
//                 else{
//                     ans += N-(abs(L-l)+abs(l-n));
//                 }
//             }
//             else{
//                 ans += abs(n-l);
//             }
//             L = n;
//         }
//         else{
//             int r = R;
//             if(r != n){
//                 while(r == n){
//                     r++;
//                     cout << r;
//                     if(r == N+1){
//                         r = 1;
//                     }
//                     if(r == L){
//                         break;
//                     }
//                 }
//                 if(r == n){
//                     ans += abs(n-r);
//                 }
//                 else{
//                     ans += N-(abs(R-r)+abs(r-n));
//                 }
//             }
//             else{
//                 ans += abs(n-r);
//             }
//             R = n;
//         }
//         cout << ans << endl;
//     }
//     cout << ans << endl;
//     return 0;
// }
int main()
{
    int N, Q;
    cin >> N >> Q;
    int L = 1, R = 2;
    int ans = 0;

    for(int i = 0; i < Q; i++) {
        char s;
        int n;
        cin >> s >> n;

        if(s == 'L') {
            int l = L;
            int i = 0;
            if(l != n) {
                while(l != n) {
                    l++;
                    i++;
                    if(l == N + 1) l = 1;  // Wrap around
                    if(l == R) break;      // Cannot overlap with R
                }
                if(l == n) {
                    ans += abs(n - L);
                } else {
                    ans += N - (abs(L - l) + abs(l - n));
                }
            }
            else {
                ans += abs(n - L);
            }
            L = n;
        }
        else {  // s == 'R'
            int r = R;
            int i = 0;
            if(r != n) {
                while(r != n) {
                    r++;
                    i++;
                    if(r == N + 1) r = 1;  // Wrap around
                    if(r == L) break;      // Cannot overlap with L
                }
                if(r == n) {
                    ans += i;
                } else {
                    ans += N - (abs(R - r) + abs(r - n));
                }
            }
            else {
                ans += abs(n - R);
            }
            R = n;
        }
    }

    cout << ans << endl;
    return 0;
}
