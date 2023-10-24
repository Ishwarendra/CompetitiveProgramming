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

    std::vector<int> c(9);
    for (int i = 0; i < 9; i++)
        std::cin >> c[i];

    std::vector<int> dp(n + 1), par(n + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (i - c[j] < 0)
                continue;

            if (dp[i - c[j]] + 1 >= dp[i])
            {
                dp[i] = dp[i - c[j]] + 1;
                par[i] = j;
            }
        }
    }

    std::string ans;
    int money = n;
    while (money > 0 and par[money] != -1)
    {
        ans += std::to_string(par[money] + 1)[0];
        money -= c[par[money]];
    }

    std::sort(std::rbegin(ans), std::rend(ans));
    std::cout << ans;
    
    return 0;
}