#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> a(n), d(m), f(k);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];
    for (int i = 0; i < m; i++)
        std::cin >> d[i];
    for (int i = 0; i < k; i++)
        std::cin >> f[i];

    std::sort(std::begin(f), std::end(f));
    f.erase(std::unique(std::begin(f), std::end(f)), std::end(f));
    k = std::size(f);

    int max = 0, smax = 0, max_id = 1;
    for (int i = 1; i < n; i++)
    {
        int d = a[i] - a[i - 1];
        if (d >= max)
            smax = max, max = d, max_id = i;
        else if (d > smax)
            smax = d;
    }

    int ans = max;
    for (int i = 0; i < m; i++)
    {
        int left = 0, right = k - 1;
        int id = -1;

        auto val = [&](int mid)
        {
            int sum = f[mid] + d[i];
            return std::max(std::abs(sum - a[max_id - 1]), std::abs(sum - a[max_id]));
        };

        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (mid - 1 < 0 || val(mid - 1) > val(mid))
                id = mid, left = mid + 1;
            else
                right = mid - 1;
        }

        ans = std::min(ans, val(id));
    }

    std::cout << std::max(ans, smax) << "\n";
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