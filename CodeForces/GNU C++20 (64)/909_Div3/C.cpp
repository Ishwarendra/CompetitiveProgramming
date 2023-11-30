#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;

void solve()
{
    int n;
    std::cin >> n;

    auto kadane = [&](std::vector<int> &a)
    {
        int n = std::size(a);
        if (n == 0)
            return -inf;

        int max_sum = -inf;
        int cur_sum = 0;
        for (int i = 0; i < n; i++)
        {
            cur_sum += a[i];
            max_sum = std::max(max_sum, cur_sum);
            if (cur_sum < 0)
                cur_sum = 0;
        }

        return max_sum;
    };

    std::vector<int> a(1);
    int ans = -inf;

    std::cin >> a[0];
    for (int i = 1; i < n; i++)
    {
        int x;
        std::cin >> x;

        if (std::abs(a.back() % 2) == std::abs(x % 2))
        {
            ans = std::max(ans, kadane(a));
            a.clear();
        }

        a.emplace_back(x);
    }

    ans = std::max(ans, kadane(a));
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