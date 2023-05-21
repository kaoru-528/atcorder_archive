#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n;
    int a[10][10];
    int b[10];
    int max =0;

    if(scanf("%d", &n) == 1);
    int c[n];
    for(int i = 0; i < n; i++){
        if(scanf("%d", &b[i]) == 1);
    }
    for(int i= 0; i < n; i++){
        for(int j = 0; j < n; j++){
            a[i][j] = b[i] % 10;
            if(b[i] < 10){
                a[i][j+1] = b[i];
                break;
            }
        }
    }

    for(int k = 0; k < n; k++){
        if(k = 0){
            for(int i= 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(max < a[i][j]){
                        max = a[i][j];
                        c[k] = max;
                        max = 0;
                    }
                }
            }
        }
        else{
            for(int i= 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    max = a[i-1][j];
                    if(max < a[i][j-1]){
                        max = a[i][j];
                    }
                    else if(max < a[i-1][j-1]){
                        max = a[i][j];
                    }
                    else if(max < a[i+1][j-1]){
                        max = a[i][j];
                    }
                    else if(max < a[i-1][j+1]){
                        max = a[i][j];
                    }
                    else if(max < a[i+1][j+11]){
                        max = a[i][j];
                    }
                    c[k] = max;
                    max = 0;
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        printf("%d",c[i]);
    }


}