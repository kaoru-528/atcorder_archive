#include <bits/stdc++.h>
using namespace std;
int main(){
    int l_1, r_1, l_2, r_2;
    int s;
    cin >> l_1 >> r_1 >> l_2 >> r_2;

    if(r_1 < l_2){
        s = 0;
    }

    else if(r_2 < l_1){
        s = 0;
    }

    else if(l_1 <= l_2){
        if(r_1 < r_2){
            s = r_1 - l_2;
        }
        else {
            s = r_2 - l_2;
        }
    }

    else if(l_1 >= l_2){
        if(r_1 > r_2){
            s = r_2 - l_1;
        }
        else {
            s = r_1 - l_1;
        }
    }
    printf("%d", s);

    return 0;
}