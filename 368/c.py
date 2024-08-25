import numpy as np

N = int(input())
A = list(map(int, input().split()))

ans = 0

for i in range(N):
    a = A[i] // 5
    b = A[i] % 5
    if b == 3 or b == 4:
        b = 3
    ans += a * 3 + b
    print(ans)

print(ans)