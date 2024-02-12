/**
 * author:  Kaoru
 * created: 10.02.2024 20:54:39
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

void generateCombinations(std::vector<std::string>& combinations, std::string current, ll length) {
    if (length == 0) {
        combinations.push_back(current);
        return;
    }

    generateCombinations(combinations, current + '0', length - 1);
    generateCombinations(combinations, current + '1', length - 1);
}

int main()
{
    ll N;
    cin >> N;
    ll aa = ceil(log2(N)) + 1;
    vll ans(aa);
    fill(ans.begin(), ans.end(), N);
    ll anss= 0;

   std::vector<std::string> combinations;
    generateCombinations(combinations, "", aa);
    for(int i = 0; i < combinations.size(); i++){
       for(int j = 0; j < combinations[i].size(); j++){
           if (combinations[i][j] == 0){
                ans[i] = int(floor(ans[i] / 2));
               if(ans[i] != 1 || ans[i] != 0){
                    ans[i] += ans[i];
               }
               else break;
           }else{
               ans[i] = ceil(ans[i] / 2);
               if(ans[i] != 1 || ans[i] != 0){
                    ans[i] += ans[i];
               }
               else break;
               print(ans);
           }

       }
        anss += ans[i];
    }
    print(anss);



    return 0;
}