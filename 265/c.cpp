#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int h,w;
    cin >> h>> w;
    vector<vector<ll>> g(h,vector<ll>(w));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            char c;
            cin >> c;
            g[i][j] = c;
        }
    }
    
    return 0;
}