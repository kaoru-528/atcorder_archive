#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    int count = 0;
    cin >> n >> m;
    int a[5000][2];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < 2; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = i + 1; j < m; j++){
            for(int k = j + 1; k < m; k++){
                for(int l = 0; l < m; l++){
                    if((a[l][0] == i && a[l][1] == j)||(a[l][1] == i && a[l][0] == j)){
                        for(int o = 0; o < m; o++){
                            if((a[o][0] == k && a[o][1] == j)||(a[o][1] == k && a[o][0] == j)){
                                for(int p = 0; p < m; p++){
                                    if((a[p][0] == i && a[p][1] == k)||(a[p][1] == i && a[p][0] == k)){
                                        count++;
                                    }
                                }
                            }
                        } 
                    }
                }
            }
        }
    }
    printf("%d", count);
    return 0;
}
