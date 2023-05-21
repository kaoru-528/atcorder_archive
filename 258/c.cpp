#include <bits/stdc++.h>
using namespace std;
using ll = long long;
char one(int n, vector<ll> s){
    char tmp1, tmp2;
    tmp1 = s[n-1];
    for(int i; i < n; i++){
        tmp2 = s[i+1];
        s[i+1] = s[i];
    }
    s[0] = tmp1;
    return s;
}
int main(){
    int n, q;
    cin >> n, q;
    vector<ll> s(n);
    vector<vector<ll>> a(q);
    for(int i; i < n; i++){
        char c;
        cin >> c;
        s[i] = c - '0';
    }
    for(int i; i < n; i++){
        for(int j; j < 2; j++){
            char d;
            cin >> d;
            s[i][j] = d - '0';
        }
    }
    

    return 0;
}