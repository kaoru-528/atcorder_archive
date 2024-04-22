/**
 * author:  Kaoru
 * created: 20.04.2024 20:58:36
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

int main() {
    int N;
    cin >> N;
    vi A(N);
    map<int, int> mp;
    rep(i, N) {
        cin >> A[i];
        mp[A[i]] = i+1;
    }
    vector<pair<int, int>> swap_operations;
    rep(i, N){
        if(A[i] != i+1){
            swap(A[i], A[mp[i+1]-1]);
            swap_operations.push_back({i+1 , mp[i+1]});
            mp[A[mp[i+1]-1]] = mp[i+1];
            mp[A[i]] = i+1;
            // for(auto itr = mp.begin(); itr != mp.end(); ++itr) {
            //     cout << "key = " << itr->first           // キーを表示
            //     << ", val = " << itr->second << "\n";    // 値を表示
            // }
        }
    }
    print(swap_operations.size());
    for (const auto& swap_op : swap_operations) {
        cout << swap_op.first << " " << swap_op.second  << endl;
    }
    return 0;
}