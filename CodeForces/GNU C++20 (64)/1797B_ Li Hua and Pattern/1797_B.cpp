#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector a(n, std::vector(n, 0));
    for (int i = 0; i < n; i++)  
    {
        for (int j = 0; j < n; j++)
            std::cin >> a[i][j];
    }

    int need = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            need += a[i][j] != a[n - 1 - i][n - 1 - j];
    }

    need /= 2;
    if (k - need >= 0 and ((k - need) % 2 == 0 || n % 2))
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
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