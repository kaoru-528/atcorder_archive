/**
 * author:  Kaoru
 * created: 27.04.2024 18:12:00
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
    int N, M;
    cin >> N >> M;
    vi A, B;
    int N, M, A[100009], B[100009];
    int dist[100009];
    vi G[100009];
    queue<int> Q;
    for(int i = 1; i <= M; i++){
        cin >> A[i] >> B[i];
        G[A[i]].pb(B[i]);
        G[B[i]].pb(A[i]);
    }
    for(int i = 1; i <= N; i++) dist[i] = -1;
    Q.push(1);
    dist[1] = 0;
    while(!Q.empty()){
        int pos = Q.front();
        Q.pop();
        rep(i, G[pos].size()){
            int to = G[pos][i];
            if(dist[to] == -1){
                dist[to] = dist[pos] + 1;
                Q.push(to);
            }
        }
    }
    for(int i = 1; i <= N; i++){
        cout << dist[i] << endl;
    }

    return 0;
}