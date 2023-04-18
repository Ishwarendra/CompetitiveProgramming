#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int N = 1e3;
constexpr int inf = 1e9;

std::vector<int> dp1(N + 1, inf); 

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::set<int> s;
    std::vector<int> wt(n), val(n);
    for (int i = 0; i < n; i++)
    {
        int b;
        std::cin >> b;
        wt[i] = dp1[b];
    }

    for (int i = 0; i < n; i++)
        std::cin >> val[i];

    std::vector<int> dp(k + 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = k; j >= wt[i]; j--)
            dp[j] = std::max(dp[j], dp[j - wt[i]] + val[i]);
    }
    
    std::cout << dp.back() << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    dp1[1] = 0; 
    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (i + i / j <= N)
                dp1[i + i / j] = std::min(dp1[i + i / j], dp1[i] + 1);
        }
    }

  
    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}