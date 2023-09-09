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
    int num = 0;
    auto fill = [&](int x, int y)
    {
        for (int i = x; i < x + 4; i++)
        {
            for (int j = y; j < y + 4; j++)
                a[i][j] = num++;
        }
    };

    for (int i = 0; i < n; i += 4)
    {
        for (int j = 0; j < n; j += 4)
            fill(i, j);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            std::cout << a[i][j] << " \n"[j == n - 1];
    }

    return 0;
}