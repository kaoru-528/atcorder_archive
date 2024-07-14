/**
 * author:  Kaoru
 * created: 13.07.2024 22:05:46
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

int N, M, A[100009], B[100009], C[100009];
vector<pair<int, int>> G[100009];

int cur[100009]; bool kakutei[100009];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> Q;
int main()
{
    cin >> N >> M;
    vi wei(N + 1);  // Adjust size to N+1 to match 1-based indexing
    rep(i, 1, N + 1) cin >> wei[i];  // Start loop from 1 to N+1 to match 1-based indexing
    for(int i = 1; i <= M; i++){
        cin >> A[i] >> B[i] >> C[i];
        G[A[i]].pb({B[i], C[i]});
        G[B[i]].pb({A[i], C[i]});
    }

    for(int i = 1; i <= N; i++){
        cur[i] = 1e9;
        kakutei[i] = false;
    }

    cur[1] = wei[1];  // Initialize with the weight of the starting node
    Q.push(make_pair(cur[1], 1));

    while(!Q.empty()){
        int pos = Q.top().second; Q.pop();

        if(kakutei[pos]) continue;

        kakutei[pos] = true;
        for(auto [next, edge_cost] : G[pos]){
            int cost = edge_cost + wei[next] + wei[pos];  // Include weights of both nodes

            if(cur[next] > cur[pos] + cost){
                cur[next] = cur[pos] + cost;
                Q.push(make_pair(cur[next], next));
            }
        }
    }
    for(int i = 1; i <= N; i++){
        if(cur[i] == 1e9){
            cout << -1 << endl;
        }
        else{
            cout << cur[i] << endl;
        }
    }
    return 0;
}
