/**
 * author:  Kaoru
 * created: 07.12.2024 20:56:18
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
    int H,W,D;
    cin >> H >> W >> D;
    vector<vector<char>> S(H,vector<char>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++ ){
            cin >> S[i][j];
        }
    }

   vector<pair<int,int>> dots;
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            if (S[i][j] == '.') {
                dots.push_back({i,j});
            }
        }
    }

    int M = (int)dots.size();
    vector<vector<int>> coverage(M);

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            int dist = abs(dots[i].first - dots[j].first) + abs(dots[i].second - dots[j].second);
            if (dist <= D) coverage[i].push_back(j);
        }
    }

    int ans = 0;
    for (int i = 0; i < M; i++) {
        for (int j = i; j < M; j++) {
            static bool used[110];
            memset(used,false,sizeof(used));
            for (int idx = 0; idx < (int)coverage[i].size(); idx++) {
                int x = coverage[i][idx];
                used[x] = true;
            }

            for (int idx = 0; idx < (int)coverage[j].size(); idx++) {
                int x = coverage[j][idx];
                used[x] = true;
            }

            int cnt = 0;
            for (int k = 0; k < M; k++) {
                if (used[k]) cnt++;
            }
            ans = max(ans, cnt);
        }
    }
    cout << ans << endl;
    return 0;
}