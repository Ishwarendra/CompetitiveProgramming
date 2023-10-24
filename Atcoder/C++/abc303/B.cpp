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
    
    int n, m;
    std::cin >> n >> m;

    std::vector a(n, std::vector(n, 1));
    for (int i = 0; i < m; i++)
    {
        std::vector<int> b(n);
        for (int j = 0; j < n; j++)
        {
            std::cin >> b[j];
            b[j]--;
        }

        for (int j = 0; j < n; j++)
        {
            if (j - 1 >= 0)
                a[b[j]][b[j - 1]] = 0;
            if (j + 1 < n) 
                a[b[j]][b[j + 1]] = 0;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
            ans += a[i][j];
    }

    std::cout << ans;
    
    return 0;
}