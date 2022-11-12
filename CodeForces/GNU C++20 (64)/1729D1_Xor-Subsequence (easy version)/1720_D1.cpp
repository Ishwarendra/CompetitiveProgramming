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

    constexpr int N = (1 << 8) + 1;
    std::vector<int> dp(n);
    dp[0] = 1;

    for (int i = 1; i < n; i++)
    {
        dp[i] = 1;
        for (int j = i - 1; j >= std::max(0, i - N); j--)
        {
            if ((a[j] ^ i) < (a[i] ^ j))
                dp[i] = std::max(dp[i], 1 + dp[j]);
        }
    }

    std::cout << dp.back() << "\n";
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
