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

vvi find(int N, int K, const vi &R, vi &current, int start, int remainingSum)
{
    vvi result;
    if (current.size() == N)
    {
        if (remainingSum == 0)
        {
            result.push_back(current);
        }
        return result;
    }

    for (int i = start; i < N; ++i)
    {
        for (int num = 1; num <= R[i]; ++num)
        {
            if (remainingSum >= num)
            {
                current.pb(num);
                vvi res = find(N, K, R, current, i + 1, remainingSum - num);
                result.insert(result.end(), res.begin(), res.end());
                current.pop_back();
            }
        }
    }
    return result;
}

int main()
{
    int N, K;
    cin >> N >> K;
    vi R(N);
    rep(i, N)
    {
        cin >> R[i];
    }

    vi current;
    int sum = accumulate(all(R), 0);

    set<vi> allCombinations;
    for (int i = K; i <= sum; i += K)
    {
        vvi combinations = find(N, K, R, current, 0, i);
        for (const auto &comb : combinations)
        {
            allCombinations.insert(comb);
        }
    }

    for (const auto &comb : allCombinations)
    {
        print(comb, " ");
    }

    return 0;
}
