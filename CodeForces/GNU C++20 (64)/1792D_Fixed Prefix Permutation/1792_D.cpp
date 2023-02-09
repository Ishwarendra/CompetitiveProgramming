#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector a(n, std::vector<int>(m, 0)), ainv(n, std::vector<int>(m, 0));
    for (int i = 0; i < n; i++)  
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> a[i][j];
            a[i][j]--;
            ainv[i][a[i][j]] = j;
        }
    }

    std::sort(std::begin(ainv), std::end(ainv));
    auto maxLen = [](auto &a, auto &b) 
    {
        int n = std::size(a);
        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i])
                return i;
        }

        return n;
    };

    for (int i = 0; i < n; i++)
    {
        auto it = std::lower_bound(std::begin(ainv), std::end(ainv), a[i]);
        int ans = 0;

        if (it != std::begin(ainv))
            ans = std::max(ans, maxLen(*std::prev(it), a[i]));

        if (it != std::end(ainv))
            ans = std::max(ans, maxLen(*it, a[i]));

        std::cout << ans << " \n"[i == n - 1];
    }
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