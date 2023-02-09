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

    std::vector<int> pos[m + 1];
    for (int i = 0; i < n; i++)  
    {
        int x;
        std::cin >> x;

        for (int j = 1; j * j <= x; j++)
        {
            if (x % j == 0)
            {
                if (j <= m)
                    pos[j].emplace_back(x);
                if (j * j != x and x / j <= m)
                    pos[x / j].emplace_back(x);
            }
        }
    }

    for (int i = 1; i <= m; i++)
        std::sort(std::begin(pos[i]), std::end(pos[i]));

    std::multiset<std::array<int, 3>> pq;
    constexpr int inf = 1e8;

    int gmax = -inf, gmin = inf;

    for (int i = 1; i <= m; i++)
    {
        if (std::empty(pos[i]))
        {
            std::cout << "-1\n";
            return;
        }

        pq.insert({pos[i][0], i, 0});
        gmax = std::max(gmax, pos[i][0]);
        gmin = std::min(gmin, pos[i][0]);
    }

    while (true)
    {
        auto [min, where1, which1] = *std::begin(pq);
        auto [max, where2, which2] = *(--std::end(pq));

        pq.erase(std::begin(pq));
        if (max - min < gmax - gmin)
            gmax = max, gmin = min;

        int sz = std::ssize(pos[where1]);
        if (which1 + 1 < sz)
            pq.insert({pos[where1][which1 + 1], where1, which1 + 1});
        else
            break;
    }

    std::cout << gmax - gmin << "\n";
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