#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int a,b,c,d,e;
    cin >> a>> b>> c>> d >> e;
    int s;
    if(a == b && b == c && d == e&& a == c){
        printf("Yes");
    }
    else if(a == c && c == d && b == e && a == d){
        printf("Yes");
    }
    else if(a == d && d == e && b == c&& a == e){
        printf("Yes");
    }
    else if(b == c && c == d && a == e&& b == d){
        printf("Yes");
    }
    else if(b == b && b == e && a == d&& b == e){
        printf("Yes");
    }
    else if(c == d && d == e && a == b&& c == e){
        printf("Yes");
    }
    else if(a == c && c == e && b == d&& a == e){
        printf("Yes");
    }
    else if(a == b && b == d && c == e&& a == d){
        printf("Yes");
    }
    else if(a == b && b == e && c == d&& a == e){
        printf("Yes");
    }
    else if(b == d && d == e && a == c&& b == e){
        printf("Yes");
    }
    else {
        printf("No");
    }

    return 0;
}
