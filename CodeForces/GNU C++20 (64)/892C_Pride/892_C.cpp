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

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    int g = 0;
    for (int i = 0; i < n; i++)
        g = std::gcd(g, a[i]);

    if (g != 1)
    {
        std::cout << -1;
        return 0;
    }

    int one = std::count(std::begin(a), std::end(a), 1);
    if (one > 0)
    {
        std::cout << n - one;
        return 0;
    }

    std::array<int, 3> best {n, 0, n - 1};
    for (int i = 0; i < n; i++)
    {
        g = 0;
        for (int j = i; j < n; j++)
        {
            g = std::gcd(g, a[j]);
            if (g == 1)
                best = std::min(best, std::array{j - i + 1, i, j});
        }
    }

    auto &[len, st, end] = best;
    len--;
    
    std::cout << len + n - 1;

    return 0;
}