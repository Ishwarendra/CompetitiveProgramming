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

    std::vector a(n, std::string(m, 'A'));
    std::vector b(m, std::string(n, 'A'));

    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    int cnt_a = 0, cnt_p = 0;
    for (int i = 0; i < n; i++)
    {
        cnt_a += std::count(std::begin(a[i]), std::end(a[i]), 'A');
        cnt_p += std::count(std::begin(a[i]), std::end(a[i]), 'P');
    }

    if (cnt_a == 0)
    {
        std::cout << "MORTAL\n";
        return;
    }

    if (cnt_p == 0)
    {
        std::cout << 0 << "\n";
        return;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            b[j][i] = a[i][j];
    }

    auto get = [](std::vector<std::string> &a)
    {
        int n = std::size(a);
        int m = std::size(a[0]);

        int ans = 4;
        if (a[0][0] == 'A' || a[0][m - 1] == 'A' or a[n - 1][0] == 'A' or a[n - 1][m - 1] == 'A')
            ans = 2;
        for (int i = 0; i < std::size(a); i++)
        {
            int cnt_a = std::count(std::begin(a[i]), std::end(a[i]), 'A');
            if (cnt_a == m)
            {
                if (i == 0 or i + 1 == std::size(a))
                    ans = std::min(ans, 1);
                else
                    ans = std::min(ans, 2);
            }
            else if (cnt_a != 0)
            {
                if (i == 0 or i + 1 == std::size(a))
                    ans = std::min(ans, 3);
            }
        }

        return ans;
    };

    int ans = std::min(get(a), get(b));
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