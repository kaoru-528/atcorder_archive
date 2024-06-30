/**
 * author:  Kaoru
 * created: 30.06.2024 20:56:13
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
    string S, T;
    cin >> S >> T;
    int num = S.size()/T.size();
    if(T.size() == 1){
        print("No");
        return 0;
    }
    int tmp = 0;
    if(S.size()%T.size() != 0){
       tmp = num+1;
       vs v(tmp);
        int j  = 0;
        rep(i, tmp)
        {
            v[i] = S.substr(j,num);
            j += num;
        }
        // print(v);
        rep(i, v.size()){
            // print(v[i][num-1]);
            if(T[i] != v[i][num-1]){
                // print(v[i][num-1]);
                // print(T[i]);
                // print(i);
                print("No");
                return 0;
            }
        }
    }
    else{
        tmp = num-1;
        vs v(tmp);
        int j  = 0;
        rep(i, tmp)
        {
            v[i] = S.substr(j,num);
            j += num;
        }
        // print(v);
        rep(i, v.size()){
            rep(j, v[i].size()){
                if(T[i] != v[i][j]){
                // print(v[i][num-1]);
                // print(T[i]);
                // print(i);
                print("No");
                return 0;
            }
            }
        }
    }
    
    print("Yes");
    return 0;
}