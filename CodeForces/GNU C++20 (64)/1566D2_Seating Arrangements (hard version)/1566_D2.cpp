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

    std::vector a(n * m, std::array<int, 2>());
    for (int i = 0; i < n * m; i++)
    {
        std::cin >> a[i][0];
        a[i][1] = i;
    }

    std::sort(std::begin(a), std::end(a));
    std::vector b(n, std::vector(m, std::array<int, 2>()));

    for (int i = 0, pos = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++, pos++)
            b[i][j] = a[pos];
    }

    auto get = [&](auto &p)
    {
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = i + 1; j < m; j++)
            {
                auto [v1, id1] = p[i];
                auto [v2, id2] = p[j];
                ans += id1 < id2 and v1 < v2;
            }
        }

        return ans;
    };

    i64 ans = 0;
    for (int i = 0; i < n; i++)
        ans += get(b[i]);

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