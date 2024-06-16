if(j < M){
                if(B[j] <= A[i]){
                    ans += A[i];
                    j++;
                    print(ans);
                }
            }
            else{
                break;
            }