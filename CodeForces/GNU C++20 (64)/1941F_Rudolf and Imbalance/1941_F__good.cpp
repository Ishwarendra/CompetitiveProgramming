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
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        if (i)
            ans = std::max(ans, a[i] - a[i - 1]);
    }
    for (int i = 0; i < m; i++)
        std::cin >> d[i];
    for (int i = 0; i < k; i++)
        std::cin >> f[i];

    std::set<int> s(std::begin(a), std::end(a));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < k; j++)
        {
            int sum = d[i] + f[j];
            if (s.count(sum))
                continue;

            s.emplace(sum);
            std::vector<int> nums(std::begin(s), std::end(s));
            int max = 0;
            for (int id = 1; id < std::size(nums); id++)
                max = std::max(max, nums[id] - nums[id - 1]);
            // if (max == 6)
            //     print(s, sum, d[i], f[j])
            s.erase(sum);
            ans = std::min(ans, max);
        }
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