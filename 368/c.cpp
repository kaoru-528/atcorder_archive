/**
 * author:  Kaoru
 * created: 24.08.2024 20:57:58
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

int main()
{
    ll N;
    cin >> N;
    vll A(N);
    for (ll i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    ll ans = 0;

    for (ll i = 0; i < N; i++)
    {
        if (ans % 3 == 0)
        {
            ll a = A[i] / 5;
            ll b = A[i] % 5;
            if (b == 3 || b == 4)
            {
                b = 3;
            }
            ans += a * 3 + b;
        }
        else if (ans % 3 == 1)
        {
            ll a = A[i] / 5;
            ll b = A[i] % 5;
            if (b == 2 || b == 3 || b == 4)
            {
                b = 2;
            }
            ans += a * 3 + b;
        }
        else if (ans % 3 == 2)
        {
            ll a = A[i] / 5;
            ll b = A[i] % 5;
            if (b == 1 || b == 2 || b == 3)
            {
                b = 1;
            }
            else if (b == 4)
            {
                b = 2;
            }
            ans += a * 3 + b;
        }
    }
    print(ans);
    return 0;
}