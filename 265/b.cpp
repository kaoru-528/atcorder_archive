#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    double n,m,t;
    cin >> n>> m>> t;
    double  a[1000000];
    for(int i = 0; i < n-1; i++){
        int b;
        cin >> b;
        a[i] = b;
    }
    vector<vector<ll>> x(n,vector<ll>(n));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < 2; j++){
            int c;
            cin >> c;
            x[i][j] = c;
        }
    }

    for(int i = 0; i < m; i++){
        a[x[i][0]-1] = a[x[i][0]-1] - x[i][1];
    }

    for(int i = 0; i < n; i++){
        t = t - a[i];
        if ( t <= 0){
            cout << "No";
            break;
        }
        if(i == n -1){
            cout << "Yes";
        }
    }
    return 0;
}