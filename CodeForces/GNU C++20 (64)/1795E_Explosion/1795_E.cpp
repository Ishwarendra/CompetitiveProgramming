#include "bits/stdc++.h"

#undef LOCAL

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr i64 inf = 1e18;

i64 apSum(int a, int d, int n)
{
    assert(d < 0);
    if (n < 0)
        return 0;

    auto firstPos = [&]()
    {
        if (a + (n - 1LL) * d >= 0)
            return n;

        int ans = (-a + d) / d;
        return ans;        
    };

    print(n, firstPos());
    n = firstPos();
    assert(a + (n - 1) * d >= 0);
    return 1LL * n * (2LL * a + 1LL * (n - 1) * d) / 2;
}

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> h(n);
    for (int i = 0; i < n; i++)  
        std::cin >> h[i];

    std::vector<i64> sum(n);

    auto pref = [&](int i, int j)
    {
        if (i > j)
            return 0LL;

        return sum[j] - (i - 1 >= 0 ? sum[i - 1] : 0LL);
    };

    // for each i, find maximum j such that h[i] >= h[j] - (j - i)

    auto get_dp = [&]()
    {
        std::stack<int> s;
        std::vector<int> a(n, -1);
        sum[0] = h[0];

        for (int i = 1; i < n; i++)
            sum[i] = sum[i - 1] + h[i];

        for (int i = 0; i < n; i++)
        {
            while (!s.empty() and h[i] < h[s.top()] + (i - s.top()))
                s.pop();

            a[i] = (s.empty() ? -1 : s.top());
            s.emplace(i);
        }   

        std::vector<i64> dp(n);
        for (int i = 1; i < n; i++)
        {
            if (a[i] == -1)
                dp[i] = pref(0, i - 1) - apSum(h[i] - 1, -1, i);
            else
            {
                dp[i] = pref(a[i] + 1, i - 1) - apSum(h[i] - 1, -1, i - a[i] - 1);
                dp[i] += dp[a[i]];
            }
        }

        print(h, a, dp)
        return dp;      
    };

    std::reverse(std::begin(h), std::end(h));
    auto dp2 = get_dp();
    std::reverse(std::begin(dp2), std::end(dp2));

    std::reverse(std::begin(h), std::end(h));
    auto dp1 = get_dp();
    
    i64 ans = inf;
    print(h, dp1, dp2)
    for (int i = 0; i < n; i++)
        ans = std::min(ans, dp1[i] + dp2[i] + h[i]);

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