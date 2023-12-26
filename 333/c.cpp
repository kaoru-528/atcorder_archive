/**
 * author:  Kaoru
 * created: 16.12.2023 20:32:44
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

long long generateRepunit(int length) {
    long long result = 0;
    for (int i = 0; i < length; ++i) {
        result = result * 10 + 1;
    }
    return result;
}

int main() {
    int N;
    cin >> N;
    ll sum = 0;
    int count = 1;
    ll sumsum_1 = 0;
    while(1){
        count++;
        int sumsum = 0;
        rep(i, count){
            sumsum = sumsum + i;
        }
        sum  = sum + sumsum;
        sumsum_1 = sumsum;
        if(N < sum) break;
    }
    int count_ans = count - 1;
    ll ans = generateRepunit(count_ans);



    int num = N - (sum -sumsum_1);
    N = num;
    count = 1;
    sumsum_1 = 0;
    sum = 0;
    while(1){
        count++;
        sum  = sum + count;
        if(N < sum) break;
    }
    count_ans = count-1;
    ans = ans + generateRepunit(count_ans);

    
    num = N - (sum - count);
    N = num;
    count = 1;
    sumsum_1 = 0;
    sum = 0;
    while(1){
       count++;
        sum  = sum + count;
        if(N < sum) break;
    }
    count_ans = count - 1;
    ans = ans + generateRepunit(count_ans);
    // if(num % 2 == 0){
    //     num = num / 2 + 1;
    //     ans = ans + generateRepunit(num);
    //     ans = ans + generateRepunit(num-1);
    // }
    // else{
    //     num = num / 2 + 1;
    //     ans = ans + generateRepunit(num);
    //     ans = ans + generateRepunit(num);
    // }
    print(ans);

    return 0;
}