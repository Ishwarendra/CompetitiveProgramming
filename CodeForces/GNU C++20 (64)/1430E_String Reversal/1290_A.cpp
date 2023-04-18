#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector a(n, 0);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    k = std::min(k, m - 1);

    int min = *std::min_element(std::begin(a), std::end(a));
    int max = *std::max_element(std::begin(a), std::end(a));

    int ans = min;
    constexpr int inf = 1e9 + 1;
    for (int x = 0; x <= k; x++)
    {
        int cur_ans = inf; 
        for (int y = 0; y + k < m; y++)
        {
            // x y      k-x (m-1-k-y)
            int z = m - 1 - k - y + k - x;
            cur_ans = std::min(cur_ans, std::max(a[x + y], a[n - z - 1]));
        }

        if (cur_ans < inf)
            ans = std::max(ans, cur_ans);
    }

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