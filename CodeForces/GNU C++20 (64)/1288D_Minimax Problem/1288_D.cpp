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

    std::vector a(n, std::vector(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            std::cin >> a[i][j];
    }

    std::array<int, 2> ans{-1, -1};

    auto good = [&](int mid)
    {
        std::vector<int> b(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] >= mid)
                    b[i] |= (1 << j);
            }
        }

        constexpr int M = 1 << 8;
        std::array<int, M> cnt{};
        for (int i = 0; i < n; i++)
            cnt[b[i]]++;

        for (int i = 0; i < n; i++)
        {
            for (int mask = 0; mask < M; mask++)
            {
                if ((mask | b[i]) == (1 << m) - 1 and cnt[mask])
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (b[j] == mask)
                        {
                            ans = {i + 1, j + 1};
                            return true;
                        }
                    }
                }
            }
        }

        return false;
    };

    int left = 0, right = 1e9;
    while (left <= right)
    {
        int mid = std::midpoint(left, right);
        if (good(mid))
            left = mid + 1;
        else
            right = mid - 1;
    }

    std::cout << ans[0] << " " << ans[1];
    
    return 0;
}