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

    std::vector<i64> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    for (int i = 1; i < n; i++)
        a[i] += a[i - 1];

    i64 ans = 0;
    for (int k = 1; k <= n; k++)
    {
        if (n % k)
            continue;

        i64 max = -inf, min = inf;
        for (int i = 0; i < n; i += k)
        {
            i64 cur = a[std::min(n, i + k) - 1];
            if (i > 0)
                cur -= a[i - 1];
            max = std::max(max, cur);
            min = std::min(min, cur);
        }

        ans = std::max(ans, max - min);
    }

    std::cout << ans << "\n";
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