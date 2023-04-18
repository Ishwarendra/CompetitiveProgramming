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
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n + 1);
    for (int i = 0; i < n; i++) 
        std::cin >> a[i + 1];

    std::vector<int> cold(k + 1), hot(k + 1);
    for (int i = 0; i < k; i++)
        std::cin >> cold[i + 1];
    for (int i = 0; i < k; i++)
        std::cin >> hot[i + 1];

    // f(i, c, cpu1, cpu2): run program i on cpu-c such that 
    // last program run on cpu-1 is cpu1 and cpu-2 is cpu2 

    std::vector dp(k + 1, inf);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        std::vector ndp(k + 1, inf);
        int cur = a[i];
        for (int last = 0; last <= k; last++)
        {
            i64 cost = (cur == last ? hot[cur] : cold[cur]);
            ndp[a[i - 1]] = std::min(ndp[a[i - 1]], dp[last] + cost);

            cost = (cur == a[i - 1] ? hot[cur] : cold[cur]);
            ndp[last] = std::min(ndp[last], dp[last] + cost);
        }
        // print(dp)
        std::swap(dp, ndp);
    }
    // print(dp)
    std::cout << *std::min_element(std::begin(dp), std::end(dp)) << "\n";
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