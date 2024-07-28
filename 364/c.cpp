/**
 * author:  Kaoru
 * created: 27.07.2024 20:55:24
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
#define YESNO(bool)            \
    if (bool)                  \
    {                          \
        cout << "YES" << "\n"; \
    }                          \
    else                       \
    {                          \
        cout << "NO" << "\n";  \
    }
#define yesno(bool)            \
    if (bool)                  \
    {                          \
        cout << "yes" << "\n"; \
    }                          \
    else                       \
    {                          \
        cout << "no" << "\n";  \
    }
#define YesNo(bool)            \
    if (bool)                  \
    {                          \
        cout << "Yes" << "\n"; \
    }                          \
    else                       \
    {                          \
        cout << "No" << "\n";  \
    }

template <typename T>
inline void print(const vector<T> &v, string s = " ") { rep(i, v.size()) cout << v[i] << (i != (ll)v.size() - 1 ? s : "\n"); }
template <typename T, typename S>
inline void print(const pair<T, S> &p) { cout << p.first << " " << p.second << "\n"; }
template <typename T>
inline void print(const T &x) { cout << x << "\n"; }
template <typename T, typename S>
inline void print(const vector<pair<T, S>> &v)
{
    for (auto &&p : v)
        print(p);
}

template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}

// int main()
// {
//     ll N, X, Y;
//     cin >> N >> X >> Y;
//     vll A(N), B(N);
//     ll asum = 0;
//     ll bsum = 0;
//     rep(i, N)
//     {
//         cin >> A[i];
//         asum += A[i];
//     }
//     rep(i, N)
//     {
//         cin >> B[i];
//         bsum += B[i];
//     }
//     if (asum <= X && bsum <= Y)
//     {
//         print(N);
//         return 0;
//     }

//     for (int bit = 0; bit < (1 << N); bit++)
//     {
//         ll A_Sum = 0;
//         ll B_Sum = 0;
//         ll num = 0;
//         for (int i = 0; i < N; ++i)
//         {
//             if (bit & (1 << i))
//             {
//                 A_Sum += A[i];
//                 B_Sum += B[i];
//                 num++;
//             }
//         }
//         if (A_Sum > X || B_Sum > Y)
//         {
//             print(num);
//             return 0;
//         }
//     }
//     return 0;
// }
int main()
{
    ll N, X, Y;
    cin >> N >> X >> Y;
    vll A(N), B(N);
    ll asum = 0;
    ll bsum = 0;
    for (ll i = 0; i < N; ++i)
    {
        cin >> A[i];
        asum += A[i];
    }
    for (ll i = 0; i < N; ++i)
    {
        cin >> B[i];
        bsum += B[i];
    }
    if (asum <= X && bsum <= Y)
    {
        print(N);
        return 0;
    }
    ll ans = 100000000;

    vi itr(N);
    iota(itr.begin(), itr.end(), 0);

    while (1)
    {
        ll A_sum = 0;
        ll B_sum = 0;
        for (ll i = 0; i < N; ++i)
        {
            A_sum += A[itr[i]];
            B_sum += B[itr[i]];
            if (A_sum > X || B_sum > Y)
            {
                ans = min(ans, i + 1);
                break;
            }
        }
        if (!next_permutation(itr.begin(), itr.end()))
            break;
    }

    print(ans);

    return 0;
}