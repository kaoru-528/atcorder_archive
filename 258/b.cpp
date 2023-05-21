#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int n;
    cin >> n;
    ll ans = 0;
    vector<vector<ll>> a(n,vector<ll>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char c;
            cin >> c;
            printf("%c", c);
            a[i][j] = c-'0';
        }
    }
    vector<int> p={1,1,1,0,0,-1,-1,-1},q={1,0,-1,1,-1,1,0,-1};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<8;k++){
                ll now=0;
                ll x=i,y=j;
                for(int l=0;l<n;l++){
                    now*=10;        //次の文字の入力のため
                    now+=a[x][y];   //数字追加
                    x+=p[k];    //動かす
                    y+=q[k];
                    x%=n;   //Nをこえたときのため
                    x+=n;   //Nを超えたとき
                    y%=n;
                    y+=n;
                    x%=n;
                    y%=n;
                }       
            ans=max(ans,now);
            }
        }
    }
  cout<<ans<<endl;
}

