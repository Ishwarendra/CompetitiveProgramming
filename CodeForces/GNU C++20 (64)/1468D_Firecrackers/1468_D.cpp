#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m, a, b;
    std::cin >> n >> m >> a >> b;

    std::vector<int> s(m);
    for (int i = 0; i < m; i++)  
        std::cin >> s[i];

    std::sort(std::begin(s), std::end(s));
    int d = std::abs(a - b) - 1;
    int have = b - 1;
    if (b < a)
        have = n - b;

    auto good = [&](int mid)
    {
        int max = 0;
        for (int i = mid - 1, add = 0; i >= 0; i--, add++)
            max = std::max(s[i] + add, max);

        return max <= have - 1;
    };

    int left = 1, right = std::min(m, d);
    int ans = 0;

    while (left <= right)
    {
        int mid = std::midpoint(left, right);
        if (good(mid))
            ans = mid, left = mid + 1;
        else
            right = mid - 1;
    }

    std::cout << ans << '\n';
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