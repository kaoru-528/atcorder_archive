#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int x,y,n;
    int sum;
    cin >> x>> y>> n;
    if(y < 3*x){
        sum = y*(n/3);
        sum = sum + x*(n%3);

        cout << sum;
    }

    else{
        sum = x*n;
        cout << sum; 
    }
    return 0;
}