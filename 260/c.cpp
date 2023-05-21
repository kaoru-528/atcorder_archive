#include <bits/stdc++.h>
using namespace std;
int main(){
     int n, x, y;
     unsigned int red = 1, blue = 0, tmp = 0;
    cin >> n >> x >> y ;
    for(int i = n; i > 1; i--){
        blue = red * x * y;
        tmp = red * (x+1);
        red = tmp;
    }
    cout<<blue<<endl;
}