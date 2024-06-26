/**
 * author:  Kaoru
 * created: 23.03.2024 20:53:57
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
//     int w;
//     int b;
//     cin >> w >> b;
//     string S = "wbwbwwbwbwbw";

//     int ans_w = w /7;
//     int ans_b = b /5;
//     int w_count2  = w%7;
//     int b_count2 =  b%5;
//     rep(i,12){
//         int w_count = 0;
//         int b_count = 0;
//     for(int j=i; j<i+w_count2 + b_count2; j++){
//         if(S[j] == 'w'){
//             w_count++;
//         }
//         else{
//             b_count++;
//         }
//     }
//         if(w_count == w_count2 && b_count == b_count2){
//             print("Yes");
//             return 0;
//         }
//     }
//     print("No");
//     return 0;
// }
int main(){
    string s = "wbwbwwbwbwbw";
  ll W, B;
  cin >> W >> B;
  string S;
  rep(i, 20) { S += s; }

  ll siz = S.size();

  vll cum_W(siz + 1), cum_B(siz + 1);
  rep(i, siz) {
    if (S[i] == 'w') {
      cum_W[i + 1] = cum_W[i] + 1;
      cum_B[i + 1] = cum_B[i];
    } else {
      cum_W[i + 1] = cum_W[i];
      cum_B[i + 1] = cum_B[i] + 1;
    }
  }

  ll ok = 0;
  rep(i, siz) {
    rep(j, i, siz) {
      if (cum_W[j] - cum_W[i] == W and cum_B[j] - cum_B[i] == B) {
        ok = 1;
      }
    }
  }

  YesNo(ok);
  return 0;
}