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
    
    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    std::set<std::array<int, 3>> s;

    while (q--)
    {
        int i, j, x;
        std::cin >> i >> j >> x;
        i--, j--;

        auto [min, max] = std::minmax(i, j);
        s.insert({min, max, x});
    }

    auto getBit = [&](int x, int pos)
    {
        return (x >> pos) & 1;
    };

    for (int i = 29; i >= 0; i--)
    {
        std::vector<std::pair<int, int>> adj[n];
        std::vector<int> forbidden(n);
        for (auto [u, v, x] : s)
        {
            if ((x >> i) & 1)
            {
                if (u == v) // self-loop ft. charmi
                    a[u] |= (1 << i);
                else
                    adj[u].emplace_back(v, x);
            }
            else
                forbidden[u] = forbidden[v] = 1;
        }

        for (int u = 0; u < n; u++)
        {
            for (auto [v, x] : adj[u])
            {            
                if (getBit(x, i) and forbidden[v])
                {
                    a[u] |= (1 << i);
                    break;
                }
            }

            if (getBit(a[u], i))
                continue;

            for (auto [v, x] : adj[u]) 
                a[v] |= (1 << i);
        }
    }

    for (int i = 0; i < n; i++)
        std::cout << a[i] << " \n"[i == n - 1];

    // for (auto [u, v, x] : s)
    //     assert(a[u] | a[v] == x);
    
    return 0;
}