#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr i64 inf = 1e18;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::map<int, int> m;
    for (int i = 0; i < n; i++)  
    {
        std::cin >> a[i];
        m[a[i]]++;
    }

    std::vector<i64> dp(n + 1, inf);
    int mex = 0;
    while (m.contains(mex))
        mex++;
    dp[mex] = 0;

    auto chmin = [&](auto &x, auto y)
    {
        if (x > y)
            x = y;
    };

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 1; j <= n; j++)
            chmin(dp[i], dp[j] + 1LL * (m[i] - 1) * j + i);
    }

    std::cout << dp[0] << "\n";
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