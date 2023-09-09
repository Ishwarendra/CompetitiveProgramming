#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector a(n, std::vector(n, 0));
    i64 sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> a[i][j];
            sum += a[i][j];
        }
    }

    i64 ans = 0;
    for (int i = 0; i < n; i++)
        ans = std::max(ans, sum - a[i][n - i - 1]);

    std::cout << ans;
    
    return 0;
}