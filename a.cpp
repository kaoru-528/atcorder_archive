/**
 * author:  Kaoru
 * created: 09.12.2023 20:59:00
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

// int main()
// {
//     int N;
//     cin >> N;
//     vll A(N);
//     vll AA(N);
//     rep(i, N) cin >> A[i];
//     vl B(N);
//     rep(i, N) {
//         if(i == 0) B[i] = 0;
//         else cin >> B[i];;
//     }
//     copy(all(A), AA.begin());
//     sort(all(AA));
//     if(AA[0] > 0) {
//         cout << "+" << endl;
//         return 0;
//     }
//     else if(AA[N-1] < 0) {
//         cout << "-" << endl;
//         return 0;
//     }
//     else{
//         if(A[0] < 0) {
//             for(long j=0; j<10^100; j++) {
//                 int count = 0;
//                 for(int i = 0; i < N; i++){
//                     A[B[i]] += A[i+1];
//                     if(A[0] > 0){
//                         cout << "+" << endl;
//                         return 0;
//                     }
//                     else if(A[B[i]] == 0){
//                         count ++;
//                         if(count == N)
//                             cout << 0 << endl;
//                         return 0;
//                     }
//                 }
//             }
//         }
//         else if(A[0] > 0) {
//             for(long j=0; j<10^100; j++) {
//                 int count = 0;
//                 for(int i = 0; i < N; i++){
//                     A[B[i]] += A[i+1];
//                     if(A[0] < 0){
//                         cout << "-" << endl;
//                         return 0;
//                     }
//                     else if(A[B[i]] == 0){
//                         count ++;
//                         if(count == N)
//                             cout << 0 << endl;
//                         return 0;
//                     }
//                 }
//             }
//         }
//     }


//     // if(A[0] == 0){
//     //     cout << 0 << endl;
//     //     return 0;
//     // }
//     // else if(A[0] < 0) {
//     //     cout << "-" << endl;
//     //     return 0;
//     // }
//     // else{
//     //     cout << "+" << endl;
//     // }
//     return 0;
// }
int main()
{
    int N;
    cin >> N;
    
    vll A(N);
    vll AA(N);
    rep(i, N) cin >> A[i];
    
    vll B(N);
    rep(i, N) {
        if (i == 0) B[i] = 0;
        else cin >> B[i];
    }
    copy(all(A), AA.begin());
    sort(all(AA));
    if(AA[0] > 0) {
        cout << "+" << endl;
        return 0;
    }
    else if(AA[N-1] < 0) {
        cout << "-" << endl;
        return 0;
    }

    for (int i = N - 2; i >= 0; --i) {
        A[i] += A[i + 1];
    }

    ll rotate = min(1000000000LL/N, (ll)N);

    for (long j = 0; j < rotate; j++) {
        vll updatedA(N, 0);
        rep(i, N) {
            updatedA[B[i]] += A[i];
        }
        copy(all(updatedA), A.begin());
    }


    if (A[0] == 0) {
        cout << 0 << endl;
    } else if (A[0] < 0) {
        cout << "-" << endl;
    } else {
        cout << "+" << endl;
    }

    return 0;
}
// int main()
// {
//     int N;
//     cin >> N;
    
//     vll A(N);
//     rep(i, N) cin >> A[i];
    
//     vll B(N);
//     rep(i, N) {
//         if (i == 0) B[i] = 0;
//         else cin >> B[i];
//     }

//     // 10^6回の反復に制限
//     ll rotate = min(100000LL-(ll)N, (ll)N);

//     for(long j=0; j<rotate; j++) {
//         for(int i = 0; i < N; i++){
//             A[B[i]] += A[i+1];
//         }
//     }

//     if (A[0] == 0) {
//         cout << 0 << endl;
//     } else if (A[0] < 0) {
//         cout << "-" << endl;
//     } else {
//         cout << "+" << endl;
//     }

//     return 0;
// }