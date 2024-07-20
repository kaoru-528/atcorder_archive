/**
 * author:  Kaoru
 * created: 20.07.2024 21:27:40
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
#define REP1(i, n) for (auto i = decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define all(...) begin(__VA_ARGS__), end(__VA_ARGS__)
#define rall(...) rbegin(__VA_ARGS__), rend(__VA_ARGS__)

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

vs createNumericPalindrome(ll n, ll a)
{
    vs palindromes;
    string half;
    int halfLength = n / 2;
    ll j = 0;

    for (ll i = pow(10, halfLength); i < pow(10, halfLength + 1); ++i)
    {
        half = to_string(i);
        string fullPalindrome = half;

        if (n % 2 == 0)
        {
            reverse(half.begin(), half.end());
        }
        else
        {
            half = half.substr(0, half.size() - 1);
            reverse(half.begin(), half.end());
        }
        fullPalindrome += half;
        palindromes.push_back(fullPalindrome);
        j++;
        if (j == a)
        {
            print(fullPalindrome);
            break;
        }
    }

    return palindromes;
}

int main()
{
    ll N;
    cin >> N;
    if (N < 10)
    {
        print(N - 1);
        return 0;
    }
    else if (N < 19)
    {
        print((N - 10) * 10 + (N - 10));
        return 0;
    }
    ll sum = 10 + 9;
    int i = 3;
    ll tmp = 10 * 9;
    while (1)
    {
        if (sum > N)
        {
            break;
        }
        if (i % 2 == 0)
        {
            tmp *= 10;
            sum += tmp;
        }
        else
        {
            sum += tmp;
        }
        i++;
    }
    ll a = N - (sum - tmp);
    vs palindromes = createNumericPalindrome(i - 1, a);
    return 0;
}
