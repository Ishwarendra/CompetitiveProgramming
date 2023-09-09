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

    int odd = 1;
    auto add = [&](int i, int j) { a[i][j] = odd; odd += 2; };
    for (int i = 0; i < n; i++)
    {
        int x = std::min(i, n - i - 1), y = n / 2;
        add(i, y);
        for (int j = 1; j <= x; j++)
            add(i, y - j), add(i, y + j);
    }

    for (int i = 0, even = 2; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 0)
                a[i][j] = even, even += 2;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            std::cout << a[i][j] << " \n"[j == n - 1];
    }

    return 0;
}