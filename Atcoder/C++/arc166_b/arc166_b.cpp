#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr i64 inf = 1e18;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::array<int, 3> nums{};
    for (int i = 0; i < 3; i++)
        std::cin >> nums[i];

    std::vector<i64> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    constexpr int m = 8;
    std::vector cost(n, std::array<i64, m>());

    auto getBit = [&](int x, int pos) { return x >> pos & 1; };
    for (int i = 0; i < n; i++)
    {
        for (int mask = 0; mask < m; mask++)
        {
            i64 L = 1;
            for (int id = 0; id < 3; id++)
            {
                if (getBit(mask, id))
                    L = std::lcm<i64>(L, nums[id]);
            } 

            if (a[i] % L == 0)
                cost[i][mask] = 0;
            else
                cost[i][mask] = L - (a[i] % L); 
        }
    }

    std::array<i64, m> dp{};
    dp.fill(inf);
    dp[0] = 0;

    for (int i = 0; i < n; i++)
    {
        std::array<i64, m> ndp{};
        ndp.fill(inf);

        for (int mask1 = 0; mask1 < m; mask1++)
        {
            for (int mask2 = 0; mask2 < m; mask2++)
            {
                for (int mask3 = 0; mask3 < m; mask3++)
                {
                    if ((mask2 | mask3) == mask1)
                        ndp[mask1] = std::min(ndp[mask1], dp[mask2] + cost[i][mask3]);
                }
            }
        }

        std::swap(ndp, dp);
    }
    
    std::cout << dp[m - 1];
    
    return 0;
}