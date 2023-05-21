#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int n;
    int c = 0; 
    int d = 0; 
    int tmp, max_val, max_in;
    cin >> n;
    vector<vector<ll>> a(n,vector<ll>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char c;
            cin >> c;
            a[i][j] = c;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] == 'W' && a[j][i] == 'L'){
                c = 1;
            }

            else if(a[i][j] == 'L' && a[j][i] == 'W'){
                c = 1;
            }
            else if(a[i][j] == 'D' && a[j][i] == 'D'){
                c = 1;   
            }
            else if(a[i][j] == '-' && a[j][i] == '-'){
                c = 1;
            }
            else{
                d = 1;  
            }

        }
    }
    if( d == 1){
        printf("incorrect");
    }
    else{
       printf("correct"); 
    }
    
    return 0;
}