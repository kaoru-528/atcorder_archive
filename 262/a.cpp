#include <bits/stdc++.h>
using namespace std;
int main()
{
    int y;
    cin >> y;
    int s;
    s = y % 4;

    if(s == 2){
        printf("%d", y);
    }
    else if(s == 3){
        printf("%d", y + 3);
    }
    else if(s == 1) {
        printf("%d", y + 1);
    }
    else {
       printf("%d", y+2); 
    }
    return 0;
}
