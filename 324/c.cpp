/**
  *  programmer:  Kaoru
*    created: 14.10.2023 20:59:31
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
    string T;
    cin >> N >> T;
    vector<pair<int, string>> t(N);
    rep(i, N){
        t[i].first = i+1;
        cin >> t[i].second;
    }
    rep(i, N){
        int count = 0;
        if(length(T) == length(t[i].second)&& compare(T, t[i].second) == 0){
            cout << t[i].first << endl;
        }
        else if(length(T) == length(t[i].second)&& compare(T, t[i].second) != 0){
            rep(j, length(T)){
                if(T[j] != t[i].second[j]){
                    count++;
                }
            }
            if(count == 1){
                cout << t[i].first << endl;
            }
        }
        else if(length(T) == length(t[i].second) + 1 ){
            rep(j, length(t[i].second)){
                if(T[j] != t[i].second[j]){
                    count++;
                }
            }
            if(count == 0){
                cout << t[i].first << endl;
            }
        }
        else if(length(T) == length(t[i].second) - 1 ){
            rep(j, length(T)){
                if(T[j] != t[i].second[j]){
                    count++;
                }
            }
            if(count == 0){
                cout << t[i].first << endl;
            }
        }
    }


    return 0;
}