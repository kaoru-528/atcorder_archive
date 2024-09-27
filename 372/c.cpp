/**
 * author:  Kaoru
 * created: 21.09.2024 20:59:29
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
    ll N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    vll X(Q);
    vs C(Q);
    rep(i, Q)
    {
        ll x;
        string c;
        cin >> x >> c;
        X[i] = x-1;
        C[i] = c;
    }

    vll ans;
    int i = 0;
    while(i < N){
        if(S[i] == 'A' && S.substr(i, 3) == "ABC"){
            ans.pb(i);
            i += 3;
        }
        else{
            i++;
        }
    }
    int cnt = ans.size();
    // vs tmp(N, "A");
    // vi cnt(N, 0);
    // rep(j, ans.size()){
    //     tmp[ans[j]] = "A";
    //     tmp[ans[j]+1] = "B";
    //     tmp[ans[j]+2] = "C";
    //     cnt[ans[j]] = 1;
    //     cnt[ans[j]+1] = 1;
    //     cnt[ans[j]+2] = 1;
    // }

    // rep(j, Q){
    //     if(cnt[X[j]] == 1){
    //         num--;
    //         print(num);
    //     }
    //     else{
    //         print(num);
    //     }
    // }

    rep(i, Q){
        ll pos = X[i];
        char newChar = C[i][0];
        ll start = 0;
        start = max(start, pos-2);
        ll end = N-2;
        end = min(end, pos+2);

       for(ll k = start; k <= end; k++){
            if(S.substr(k, 3) == "ABC") cnt--;
        }
        // print(cnt);

        S[pos] = newChar;

        for(ll k = start; k <= end; k++){
            // print(S.substr(k, 3));
            // cout << "i: " << i << " k: " << k << endl;
            if(S.substr(k, 3) == "ABC") cnt++;
        }
        // print(S);

        print(cnt);
    }

    return 0;
}