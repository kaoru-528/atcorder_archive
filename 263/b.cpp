#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int n;
    int count = 0;
    int a[100];
    cin >> n;
    int b = 1;
    for(int i = 0;i < n-1; i++){
        cin >> a[i];
    }

    while(b != n){
        for(int i = 0;i < n; i++){
            if(a[i] == b){
                b = i + 2;
                count++;
                break;
            }
        }
    }

    printf("%d", count);
    return 0;
}