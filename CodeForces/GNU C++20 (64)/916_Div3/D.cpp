#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void read(auto &a)
{
    for (auto &x : a)
        std::cin >> x;
}

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a[3];
    for (int i = 0; i < 3; i++)
    {
        a[i].resize(n);
        read(a[i]);
    }

    auto getBit = [&](int x, int pos) { return x >> pos & 1; };

    std::array<int, 8> dp{};
    for (int i = 0; i < n; i++)
    {
        auto ndp = dp;
        for (int mask = 0; mask < 8; mask++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (getBit(mask, k))
                    continue;

                ndp[mask | (1 << k)] = std::max(ndp[mask | (1 << k)], dp[mask] + a[k][i]);
            }
        }

        std::swap(dp, ndp);
    }

    std::cout << dp.back() << "\n";
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