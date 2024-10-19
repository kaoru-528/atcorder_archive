/**
 * author:  Kaoru
 * created: 19.10.2024 20:57:15
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

    vector<int> A(N);  // おもちゃのサイズ
    vector<int> B(N - 1);  // 箱のサイズ

    for (int i = 0; i < N; i++) {
        cin >> A[i];  // おもちゃのサイズを入力
    }
    for (int i = 0; i < N - 1; i++) {
        cin >> B[i];  // 箱のサイズを入力
    }

    // おもちゃと箱を昇順にソート
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // 新しい箱のサイズを決定する
    int max_required_box_size = 0;  // 新しい箱のサイズ

    // 各おもちゃに対して
    for (int i = 0; i < N; i++) {
        bool can_fit = false;  // 現在のおもちゃが入る箱が見つかったか
        for (int j = 0; j < N - 1; j++) {
            if (A[i] <= B[j]) {  // おもちゃが箱に収まる場合
                can_fit = true;  // 箱に収まる
                break;
            }
        }
        if (!can_fit) {
            // 収まらなかったおもちゃの中で最大のサイズを記録
            max_required_box_size = max(max_required_box_size, A[i]);
        }
    }

    // 収まらなかったおもちゃの最大のサイズを出力
    cout << max(max_required_box_size, 0) << endl;

    return 0;
}