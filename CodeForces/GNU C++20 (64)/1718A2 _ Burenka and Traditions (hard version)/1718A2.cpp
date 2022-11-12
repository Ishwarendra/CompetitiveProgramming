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

    std::vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++)
        pref[i] ^= pref[i - 1] ^ a[i - 1];

    std::map<int, int> lastFound;
    lastFound[0] = 0;
    std::vector<int> dp(n + 1, n + 1);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1] + (a[i - 1] != 0);
        if (lastFound.contains(pref[i]))
            dp[i] = std::min(dp[i], dp[lastFound[pref[i]]] + i - lastFound[pref[i]] - 1);

        lastFound[pref[i]] = i;
    }
    std::cout << dp[n] << "\n";
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