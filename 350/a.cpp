/**
 * author:  Kaoru
 * created: 20.04.2024 20:58:40
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

// int main()
// {
//     string S;
//     cin >> S;

//     if(S[3] == '3'&& S[4] == '1'&& S[5] == '6'){
//         print("No");
//         return 0;
//     }
//     else if(S[3] == '0'&& S[4] == '0'&& S[5] == '0'){
//         print("No");
//         return 0;
//     }
//     else{
//         for(int i = 0; i <= 3; i++){
//             for(int j = 0; j <= 4; j++){
//                 for(int k = 0; k <= 9; k++){
//                     char a = '0' + i;
//                     char b = '0' + j;
//                     char c = '0' + k;
//                     if(a == S[3] && b == S[4] && c == S[5]){
//                         print("Yes");
//                         return 0;
//                     }
//                 }
//             }
//         }
//         print("No");
//     }
//     return 0;
// }

// bool isValidContestAbbreviation(string S) {
//     if (S.substr(0, 3) != "ABC") {
//         return false;
//     }
//     string number_part = S.substr(3);
//     for (char c : number_part) {
//         if (!isdigit(c)) {
//             return false;
//         }
//     }
//     int contest_number = stoi(number_part);
//     if (contest_number < 1 || contest_number > 349 || contest_number == 316) {
//         return false;
//     }
//     return true;
// }

// int main() {
//     string contest_abbreviation;
//     cin >> contest_abbreviation;
//     if (isValidContestAbbreviation(contest_abbreviation)) {
//         print("Yes");
//     } else {
//         print("No");

//     }
    
//     return 0;
// }

int main()
{
    string S;
    cin >> S;
    int tmp = stoi(S.substr(3, 3));
    for(int i = 1; i <= 349; i++){
        if(tmp == 316){
            print("No");
            return 0;
        }
        else if(i == tmp){
            print("Yes");
            return 0;
        }
    }
    print("No");
    return 0;
}