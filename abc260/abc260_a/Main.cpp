#include <bits/stdc++.h>
using namespace std;
int main(){
    char x[3];
    
    cin >> x;
    if(x[0] != x[1]&&x[0] != x[2]){
        printf("%c", x[0]);
    }
    else if(x[0] != x[1] && x[1] != x[2]){
        printf("%c", x[1]);
    }
    else if(x[2] != x[1]&&x[2] != x[0]){
        printf("%c", x[2]);
    }
    else{
        printf("-1");
    }
    return 0;
}
