/**
  *  programmer:  Kaoru
*    created: 21.10.2023 20:57:08
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

int main()
{
    int N;
    cin >> N;
    vector<pii> t(N);
    int count[9] = {0};
    rep(i, N){
        cin >> t[i].first  >> t[i].second;
    }
    int ans = 0;

    for(int i = 0; i <= 24; i++){
        int num = 0;
        rep(j,N){
            if((9 <= (i + t[i].second) % 24) && (((i+t[i].second) % 24) <= 17)){
                count[i - 9] += t[j].first;
            }
        }
        ans = max(ans, num);
    }
    int max = 0;
    rep(i,8){
        if(max < count[i]){
            max = count[i];
        }
    }
    cout << max << endl;
    return 0;
}