/**
 * author:  Kaoru
 * created: 11.05.2024 20:53:53
 **/

#include <bits/stdc++.h>

using namespace std;


int main()
{
    int N;
    cin >> N;
    vi A(N);
    rep(i, N) cin >> A[i];

    rep(i, N)
    {
        if(A[0] < A[i])
        {
            print(i+1);
            return 0;
        }
    }
    print(-1); // (A[0] is the maximum value in the array A

    return 0;
}