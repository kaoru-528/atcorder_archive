/**
 * author:  Kaoru
 * created: 18.05.2024 12:59:06
 **/

#include <bits/stdc++.h>

using namespace std;
int main()
{
    long long N;
    cin >> N;
    vector<long long> A(N);
    vector<long long> B(N);
    for(int i = 0; i < N; i++)
    {
        long long a, C;
        cin >> a >> C;
        A[a-1] = C;
        B[a-1] = i+1;
    }
    sort(A.begin(), A.end());
    for(int i = 0; i < N; i++)
    {
        auto it = lower_bound(A.begin(), A.end(), B[i]-1);
        if(it - a.begin() != 0){

        }
    }

    return 0;
}