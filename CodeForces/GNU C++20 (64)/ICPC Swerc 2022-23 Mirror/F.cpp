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

    std::vector edges(m, std::array {-1, -1});
    std::map<std::array<int, 2>, int> company;
    std::vector<int> deg(n), adj[n];

    for (auto &edge : edges)
    {
        std::cin >> edge[0] >> edge[1];
        edge[0]--, edge[1]--;

        deg[edge[0]]++;
        deg[edge[1]]++;
        adj[edge[0]].emplace_back(edge[1]);
        adj[edge[1]].emplace_back(edge[0]);
    }

    if (n == 3 and deg[0] == deg[1] and deg[1] == deg[2] and deg[0] == 2)
    {
        std::cout << "3\n1 2 3\n";
        return;
    }

    int start = std::min_element(std::begin(deg), std::end(deg)) - std::begin(deg);

    for (auto v : adj[start])
        company[{v, start}] = company[{start, v}] = 2;

    int k = 2;
    if (deg[start] == n - 1)
    {
        k++;
        int v = adj[start][0];
        company[{v, start}] = company[{start, v}] = 3;
    }

    std::cout << k << "\n";
    for (auto [u, v] : edges)
    {
        if (company.contains({u, v}))
            std::cout << company[{u, v}] << " ";
        else
            std::cout << "1 ";
    }

    std::cout << "\n";
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