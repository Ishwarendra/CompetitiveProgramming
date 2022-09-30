#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<std::array<int, 2>> dirs {{2, 1}, {-2, -1}, {2, -1}, {-2, 1}};
    auto safe = [&](int i, int j)
    {
        return i >= 0 and j >= 0 and i < n and j < m;
    };

    auto check = [&](int x, int y)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                for (auto [dx, dy] : dirs)
                    if (safe(x + dx, y + dy) or safe(x + dy, y + dx))
                        return false;
            }
        }
        return true;
    };

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (check(i, j))
            {
                std::cout << i + 1 << " " << j + 1 << "\n";
                return;
            }
        }
    }

    std::cout << n << " " << m << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}