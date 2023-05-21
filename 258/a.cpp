#include <bits/stdc++.h>
using namespace std;
int main()
{
    int X;
    cin >> X;
    int H = X < 60 ? 21 : 22;   //60以上なら22以下なら21
    int M = X % 60;
    printf("%d:%02d", H, M);
    return 0;
}