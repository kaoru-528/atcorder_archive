/**
 * author:  Kaoru
 * created: 18.05.2024 12:58:49
 **/

#include <bits/stdc++.h>

using namespace std;


int main()
{
    int N;
    cin >> N;
    int sum = 0;
    int count = 0;
    int tmp = 1;

    while(1){
        if(N >= sum){
            if(count == 0){
            sum += 1;
            count++;
        }
        else{
            tmp = tmp*2;
            sum += tmp;
        }
        count++;
        }
        else{
            cout << count-1 << endl;
            return 0;
        }
    }

    return 0;
}