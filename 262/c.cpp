#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int count = 0;
    cin >> n;
    int a[500000];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
        if(a[i] < a[j]){
            if(i + 1 == a[i]){
                if(j + 1 == a[j]){
                    count++;
                }
            }
        }
        else{
            if(i + 1 == a[j]){
                if(j + 1 == a[i]){
                    count++;
                }
            }
        }
    }
}
    printf("%d", count);
    return 0;
}
