// /**
//  * author:  Kaoru
//  * created: 25.05.2024 21:39:04
//  **/

// #include <bits/stdc++.h>

// using namespace std;

// #if __has_include(<atcoder/all>)
// #include <atcoder/all>
// using namespace atcoder;
// #endif

// using ull = unsigned long long;
// using ll = long long;
// using vi = vector<int>;
// using vl = vector<long>;
// using vll = vector<long long>;
// using vvi = vector<vi>;
// using vvl = vector<vl>;
// using vvll = vector<vll>;
// using vs = vector<string>;
// using pii = pair<int, int>;

// #define OVERLOAD_REP(_1, _2, _3, name, ...) name
// #define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
// #define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
// #define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
// #define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
// #define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)

// #define pb push_back
// #define YESNO(bool) if(bool){cout<<"YES"<<"\n";}else{cout<<"NO"<<"\n";}
// #define yesno(bool) if(bool){cout<<"yes"<<"\n";}else{cout<<"no"<<"\n";}
// #define YesNo(bool) if(bool){cout<<"Yes"<<"\n";}else{cout<<"No"<<"\n";}

// template <typename T> inline void print(const vector<T>& v, string s = " "){rep(i, v.size()) cout << v[i] << (i != (ll)v.size() - 1 ? s : "\n");}
// template <typename T, typename S> inline void print(const pair<T, S>& p){cout << p.first << " " << p.second << "\n";}
// template <typename T> inline void print(const T& x) {cout << x << "\n";}
// template <typename T, typename S> inline void print(const vector<pair<T, S>>& v){for (auto&& p : v) print(p);}

// template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
// template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

// ll mod = 1000000000;
// int main()
// {
//     ll N;
//     cin >> N;
//     vll L(N), R(N);
//     ll lmin = mod, rmax = 0;
//     rep(i, N){
//         cin >> L[i] >> R[i];
//         lmin = min(lmin, L[i]);
//         rmax = max(rmax, R[i]);
//     }
//     vll B(mod, 0);
//     rep(i, N){
//         B[L[i]]++;
//         B[R[i]+1]--;
//     }

//     vll ans(mod, 0);
//     ll count = 0;
//     for(int i = lmin; i < rmax; i++){
//         ans[i+1] = ans[i] + B[i];
//         if(ans[i] > 1 && ans[i] > ans[i-1]){
//             count++;
//         }
//     }
//     print(count);
//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

int main() {
    ll N;
    cin >> N;
    vector<pair<ll, int>> events;
    for (ll i = 0; i < N; ++i) {
        ll l, r;
        cin >> l >> r;
        events.push_back({l, 1});
        events.push_back({r + 1, -1});
    }

    sort(events.begin(), events.end(), [](const pair<ll, int>& a, const pair<ll, int>& b) {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    });

    ll active_intervals = 0;
    ll count = 0;

    for (const auto& event : events) {
        if (event.second == 1) {
            count += active_intervals;
            active_intervals++;
        }
        else {
            active_intervals--;
        }
    }

    cout << count << endl;
    return 0;
}
