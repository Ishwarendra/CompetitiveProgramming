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

    int sum = std::accumulate(std::begin(a), std::end(a), 0);
    std::vector<int> dp(sum + 1);

    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        std::vector<int> ndp(sum + 1);
        for (int j = 0; j <= sum; j++)
        {
            ndp[j] |= dp[j];
            if (j - a[i - 1] >= 0 and dp[j - a[i - 1]])
                ndp[j] |= 1;
        }

        std::swap(dp, ndp);
    }   

    std::cout << (dp[sum / 2] and sum % 2 == 0 ? "YES\n" : "NO\n");
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