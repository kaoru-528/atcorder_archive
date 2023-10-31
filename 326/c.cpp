/**
  *  programmer:  Kaoru
*    created: 28.10.2023 20:26:30
**/

#include <bits/stdc++.h>
using namespace std;

#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)
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
#define YESNO(bool) if(bool){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define yesno(bool) if(bool){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

// int main()
// {
//     int N,M;
//     cin >> N >> M;
//     vl a(N);
//     rep(i,N){
//         cin >> a[i];
//     }
//     int num = 0;
//     int Max = 0;
//     sort(begin(a), end(a));
//     rep(i ,N){
//         int count = 0;
//         int num = 0;
//         num = a[i] + M;
//         for(int j = i; j < N; j++){
//             if(a[j] < num){
//                 count++;
//             }
//         }
//         Max = max(Max, count);
//     }
//     cout << Max << endl;

//     return 0;
// }

int main() {
    int N, M;
    cin >> N >> M;
    vl a(N);
    rep(i, N) {
        cin >> a[i];
    }

    sort(all(a));

    int Max = 0;
    int left = 0;
    for (int right = 0; right < N; right++) {
        while (a[right] - a[left] > M - 1) {
            left++;
        }
        Max = max(Max, right - left + 1);
    }

    cout << Max << endl;

    return 0;
}