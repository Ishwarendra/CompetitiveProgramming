#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        a[i]--;
    }

    if (std::size(std::set(std::begin(a), std::end(a))) != n)
        std::cout << "-1\n";
    else
    {
        i64 cycle = 1;
        for (int i = 0; i < n; ++i)
        {
            std::set<int> vis;
            int u = i;
            while (!vis.count(u))
            {
                vis.emplace(u);
                u = a[u];
            }

            int sz = std::size(vis);
            if (sz % 2 == 0)
                sz /= 2;

            cycle = std::lcm<i64>(cycle, sz);
        }

        std::cout << cycle;
    }
    
    return 0;
}