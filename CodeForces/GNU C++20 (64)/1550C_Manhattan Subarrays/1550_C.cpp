#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    auto monotone = [&](int x, int y, int z)
    {
        return (x <= y and y <= z) or (x >= y and y >= z);
    };

    auto count = [&](int len)
    {
        if (len > 4)
            return n - len + 1;
        if (len < 3)
            return 0;

        int ans = 0;
        for (int i = 0; i < n - len + 1; i++)
        {
            std::vector b(std::begin(a) + i, std::begin(a) + i + len);
            int can = 0;

            for (int x1 = 0; x1 < len; x1++)
            {
                for (int x2 = x1 + 1; x2 < len; x2++)
                {
                    for (int x3 = x2 + 1; x3 < len; x3++)
                        can |= monotone(b[x1], b[x2], b[x3]);
                }
            }

            print(b, can)
            ans += can;
        }

        return ans;
    };

    i64 ans = 0;
    for (int i = 1; i <= n; i++)
        ans += count(i);

    ans = 1LL * n * (n + 1) / 2 - ans;
    std::cout << ans << "\n";
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