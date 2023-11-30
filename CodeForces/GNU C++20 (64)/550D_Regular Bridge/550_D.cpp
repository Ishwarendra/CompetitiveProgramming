#include "bits/stdc++.h"

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
    
    int k;
    std::cin >> k;

    if (k % 2 == 0)
    {
        std::cout << "NO";
        return 0;
    }

    if (k == 1)
    {
        std::cout << "YES\n2 1\n1 2";
        return 0;
    }

    std::cout << "YES\n";
    std::vector<std::pair<int, int>> edges;

    auto work = [&](int st)
    {
        for (int i = st + 1; i < st + k; i++)        
            edges.emplace_back(st, i);

        for (int i = st + 1; i < st + k; i++)
        {
            for (int j = i + 1; j < st + k; j++)
            {
                if (i % 2 == (st + 1) % 2 and j == i + 1)
                    continue;

                edges.emplace_back(i, j);
            }
            edges.emplace_back(i, st + k);
            edges.emplace_back(i, st + k + 1);
        }

        edges.emplace_back(st + k, st + k + 1);
    };

    work(1);
    work(k + 3);
    edges.emplace_back(1, k + 3);

    std::cout << 2 * k + 4 << " " << std::size(edges) << '\n';
    std::vector<int> deg(2 * k + 5);
    deg[0] = k;
    for (auto &[u, v] : edges)
    {
        deg[u]++, deg[v]++;
        std::cout << u << " " << v << "\n";
    }

    for (auto x : deg)
        assert(x == k);

    return 0;
}