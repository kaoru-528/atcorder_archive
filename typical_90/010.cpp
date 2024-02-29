/**
 * author:  Kaoru
 * created: 27.02.2024 00:30:11
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
    vvi A(N, vi(2));

    rep(i, N){
        rep(j, 2){
            cin >> A.at(i).at(j);
        }
    }

    int Q;
    cin >> Q;
    vvi B(Q, vi(2));
    rep(i, Q){
        rep(j, 2){
            cin >> B.at(i).at(j);
        }
    }

    // 計算時間がかかる
    // rep(i, Q){
    //     int ans_1 = 0;
    //     int ans_2 = 0;
    //     for(int j = B.at(i).at(0) -1 ; j <= B.at(i).at(1)- 1; j++){
    //         if(A.at(j).at(0) == 1){
    //             ans_1 += A.at(j).at(1);
    //         }
    //         else{
    //             ans_2 += A.at(j).at(1);
    //         }
    //     }
    //     cout << ans_1 << " " << ans_2 << endl;
    // }

    vi ans_1(N+1, 0);
    vi ans_2(N+1, 0);
    rep(i,N){
        if(A.at(i).at(0) == 1){
            ans_1[i+1] = A.at(i).at(1) + ans_1[i];
            ans_2[i+1] = ans_2[i];
        }
        else{
            ans_2[i+1] = A.at(i).at(1) + ans_2[i];
            ans_1[i+1] = ans_1[i];
        }
    }
    rep(i, Q){
        cout << ans_1[B.at(i).at(1)] - ans_1[B.at(i).at(0) - 1] << " " << ans_2[B.at(i).at(1)] - ans_2[B.at(i).at(0) - 1] << endl;
    }

    return 0;
}