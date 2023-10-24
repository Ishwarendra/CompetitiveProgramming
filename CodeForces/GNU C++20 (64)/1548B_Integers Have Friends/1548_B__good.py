from math import gcd

def gcd_range(a):
    g = 0
    for i in a:
        g = gcd(g, i)
    return g 

for _ in range(int(input())):
    n = int(input())
    a = [int(x) for x in input().split()]
    n -= 1
    d = [abs(a[i + 1] - a[i]) for i in range(n)]

    ans = 0
    for i in range(n):
        for j in range(i, n):
            if gcd_range(d[i: j+1]) != 1:
                ans = max(ans, j - i + 1)

    print(ans + 1)