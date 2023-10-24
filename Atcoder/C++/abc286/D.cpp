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
    
    int n, x;
    std::cin >> n >> x;

    std::vector<int> weight;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        std::cin >> a >> b;
        for (int _ = 0; _ < b; _++)
            weight.emplace_back(a);
    }

    int sz = std::size(weight);
    std::vector dp(sz + 1, std::vector(x + 1, 0));

    for (int i = 0; i <= sz; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= sz; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            dp[i][j] |= dp[i - 1][j];
            if (j - weight[i - 1] >= 0)
                dp[i][j] |= dp[i - 1][j - weight[i - 1]];
        }
    }

    std::cout << (dp[sz][x] ? "Yes\n" : "No\n");

    return 0;
}