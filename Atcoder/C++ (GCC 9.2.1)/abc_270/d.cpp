#include <bits/stdc++.h>

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
    
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(k);
    for (int i = 0; i < k; i++)
        std::cin >> a[i];

    std::vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (a[j] > i)
                break;
            
            dp[i] = std::max(dp[i], a[j] + i - a[j] - dp[i - a[j]]);
        }
    }
  
    std::cout << dp[n];
    
    return 0;
}