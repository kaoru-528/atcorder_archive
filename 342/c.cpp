/**
 * author:  Kaoru
 * created: 24.02.2024 20:58:25
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

std::string replaceOtherStr(std::string &replacedStr, std::string from, std::string to) {
    const unsigned int pos = replacedStr.find(from);
    const int len = from.length();

    if (pos == std::string::npos || from.empty()) {
        return replacedStr;
    }

    return replacedStr.replace(pos, len, to);
}

int main()
{
    int N;
    cin >> N;
    string S;
    cin >> S;
    int Q;
    cin >> Q;
    vector<vector<string>> A(Q, vector<string>(2));
    rep(i, Q){
        rep(j, 2){
            cin >> A[i][j];
        }
    }

    rep(i, Q){
        if(A[i][0] != A[i][1]){
            replaceOtherStr(S, A[i][0], A[i][1]);
            print(S);
        }
    }

    return 0;
}

int main() {
    ll N;
    cin >> N;
    string S;
    cin >> S;
    ll Q;
    cin >> Q;
    vector<pair<char, char>> A(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> A[i].first >> A[i].second;
    }

    for (int i = 0; i < Q; ++i) {
        if (A[i].first != A[i].second) {
            int npos = S.find(A[i].first);
            if(npos != -1){
                replace(all(S), A[i].first, A[i].second);
            }
        }
    }

    print(S);
    return 0;
}
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll N;
    cin >> N;
    
    string S;
    cin >> S;
    
    ll Q;
    cin >> Q;
    
    vector<pair<char, char>> A(Q);
    
    for (int i = 0; i < Q; ++i) {
        cin >> A[i].first >> A[i].second;
    }

    for (int i = 0; i < Q; ++i) {
        if (A[i].first != A[i].second) {
            for (auto &c : S) {
                if (c == A[i].first) {
                    c = A[i].second;
                }
            }
        }
    }

    print(S);
    return 0;
}