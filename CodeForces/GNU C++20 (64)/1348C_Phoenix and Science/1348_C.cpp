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

    std::vector<int> ans;
    n--;

    auto get = [&](int x)
    {
        return (n - 2 * x) / 2;
    };

    int cur = 1;
    while (n > 2 * cur)
    {
        int i = std::min(cur, get(cur));
        cur += i;
        ans.emplace_back(i);
        n -= std::min(n, cur);

    }

    if (cur <= n and n <= 2 * cur)
        ans.emplace_back(n - cur), n = 0;

    std::cout << std::size(ans) << "\n";
    for (int i = 0; i < std::size(ans); i++)
        std::cout << ans[i] << " \n"[i + 1 == std::size(ans)];
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