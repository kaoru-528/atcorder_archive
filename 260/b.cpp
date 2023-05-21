#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
     int n, x, y, z;
     int tmp, max_val, max_in;
    cin >> n >> x >> y >> z;
    vector<vector<ll>> a(n,vector<ll>(n));
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < n; j++){
            int c;
            cin >> c;
            a[i][j] = c;
        }
    }

    max_val = a[0][0];
    max_in = 0;

    for(int i = 0; i < n; i++){
        if (a[0][i] > max_val) {
            max_val = a[0][i];
            max_in = i;
        }
    }
    printf("%d", max_in+1);
    return 0;
}
