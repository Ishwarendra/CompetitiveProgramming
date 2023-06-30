#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int w, n, d;
    std::cin >> w >> n >> d;

    std::vector<int> a(w);
    for (int i = 0; i < w; i++)
    {
        std::cin >> a[i];
        a[i]--;
    }

    auto palin = [&]()
    {
        int i = 0, j = w - 1;
        while (i < j)
        {
            if (a[i++] != a[j--])
                return false;
        }

        return true;
    };

    if (palin())
    {
        std::cout << "0\n";
        return;
    }

    int i = 0, j = w - 1;

    auto options = [&](int x) -> std::pair<std::vector<int>, std::set<int>>
    {
        std::set<int> cyc { x };
        std::vector<int> cycle { x };

        while (!cyc.count((x + d) % n))
        {
            x = (x + d) % n;
            cyc.emplace(x);
            cycle.emplace_back(x);
        }

        return {cycle, cyc};
    };

    i64 ans = 0;
    while (i < j)
    {
        auto [st, st_set] = options(a[i]);
        auto [en, en_set] = options(a[j]);

        int cur_ans = 1e9;
        for (auto x = 0; x < std::size(st); x++)
        {
            for (auto y = 0; y < std::size(en); y++)
            {
                if (st[x] == en[y])
                    cur_ans = std::min(cur_ans, x + y);
            }
        }

        i++, j--;
        ans += cur_ans;
    }

    if (ans < 1e9)
        std::cout << ans << "\n";
    else
        std::cout << "IMPOSSIBLE\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    for (int i = 1; i <= t; i++)
    {
        std::cout << "Case #" << i << ": ";
        solve();
    }
    
    return 0;
}