#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// int main(){
//     int n;
//     int m = 0;
//     int tmp, max_val, max_in;
//     cin >> n;
//     int count[n] ={0};
//     vector<vector<ll>> a(n,vector<ll>(n));
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < n; j++){
//             char c;
//             cin >> c;
//             a[i][j] = c;
//         }
//     }

//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < n; j++){
//             for(int m = 0; m < n; m++){
//                 if(a[j][i] != a[j][m]){
//                     count[i] = 0; 
//                 }
//                 else{
//                     count[i] += 1;
//                 }
//             }
//         }
//     }
//     return 0;
// }

int main(){
   int n;
   int con = 1;
   cin >> n; 
   string a[n];
   for(int i = 0; i < n; i++){
        cin >> a[i];
   }
   for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){

            if(a[i] == a[j]){
                a[j] = a[j] + c
            }
        }
   }
}