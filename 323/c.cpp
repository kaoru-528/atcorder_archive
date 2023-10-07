/**
  *  programmer:  Kaoru
*    created: 07.10.2023 20:32:59
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
    int M;
    cin >> N >>M;

    ll count[N] = {0};

    int score[M];
    rep(i, M){
        cin >> score[i];
    }


    string a[N];

    rep(i, N) {
        cin >> a[i];
    }
    rep(i, N){
        rep(j, M){
            if(a[i][j] == 'o'){
                count[i] += score[j];
            }
        }
        count[i] += i+1;
    }

    rep(i, N){
        int a = 0;
        if(count[i] == max_element(count)){
            cout << a << endl;
        }
        else{

        }
    }
    return 0;
}