#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int Log(int num, int den)
{
    if (num < den)
        return -std::__lg(den / num);

    int x = (num + den - 1) / den;
    int lg2 = std::__lg(x);
    if (1LL << lg2 == x)   
        return lg2;

    return lg2 + 1;
}

void solve()
{
    int n;
    std::cin >> n;

    std::vector a(n, std::array<int, 2>());
    for (int i = 0; i < n; i++)  
    {
        std::cin >> a[i][0];
        a[i][1] = 0;
    }

    i64 ans = 0;
    for (int i = 1; i < n; i++)
    {
        int bigger = 0;
        if (a[i - 1][1] > 30)
            bigger = 1;
        else if ((1LL << a[i - 1][1]) * a[i - 1][0] > a[i][0])
            bigger = 1;

        if (!bigger)
            continue;

        int add = a[i - 1][1] + Log(a[i - 1][0], a[i][0]);
        a[i][1] = add;
        ans += add;
    }

    std::cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}