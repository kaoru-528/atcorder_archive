/**
  *  programmer:  Kaoru
*    created: 21.10.2023 21:59:07
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

    vector<int> W(N), X(N);
    for (int i = 0; i < N; i++) {
        cin >> W[i] >> X[i];
    }
    int max_attendees = 0;
    for (int start_hour = 0; start_hour < 24; start_hour++) {
        int end_hour = (start_hour + 1) % 24;
        int attendees = 0;
        for (int i = 0; i < N; i++) {
            if ((start_hour <= X[i] && X[i] < 18 && X[i] + 1 <= end_hour) || (X[i] < 9 && X[i] + 1 <= end_hour)) {
                attendees += W[i];
            }
        }
        max_attendees = max(max_attendees, attendees);
    }

    cout << max_attendees << endl;

    return 0;
}