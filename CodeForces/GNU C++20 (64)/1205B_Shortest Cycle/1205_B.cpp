#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;
constexpr int M = 64;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<i64> a, cnt(M);
    auto getBit = [&](i64 x, int pos)
    {
        return (x >> pos) & 1LL;
    };

    for (int i = 0; i < n; i++)
    {
        i64 x;
        std::cin >> x;
        if (x)
            a.emplace_back(x);

        for (int j = 0; j < M; j++)
            cnt[j] += getBit(x, j);
    }

    for (int i = 0; i < M; i++)
    {
        if (cnt[i] >= 3)
        {
            std::cout << "3\n";
            std::exit(0);
        }
    }

    n = std::size(a);

    if (n == 0)
    {
        std::cout << "-1\n";
        std::exit(0);
    }

    std::vector<int> adj[n];
    std::vector dp(n, std::vector<int>(M));
    std::vector<int> depth(n, -1);

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((a[i] & a[j]) == 0)
                continue;

            adj[i].emplace_back(j);
            adj[j].emplace_back(i);
        }
    }

    std::vector vis(n, 0);
    std::function<void(int)> bfs_tree;
    bfs_tree = [&](int src)
    {
        dp[src][0] = src;
        depth[src] = 0;
        std::queue<int> q;
        q.emplace(src);
        vis[src] = 1;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (int v : adj[u])
            {
                if (!vis[v])
                {
                    vis[v] = 1;
                    q.emplace(v);
                    dp[v][0] = u;
                    depth[v] = depth[u] + 1;
                }
            }
        }
    };

    for (int i = 0; i < n; i++)
    {
        if (!vis[i]) 
            bfs_tree(i);
    }

    for (int j = 1; j < M; j++)
    {
        for (int i = 0; i < n; i++)
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
    }

    auto lca = [&](int u, int v)
    {
        if (depth[u] < depth[v])
            std::swap(u, v);

        int diff = depth[u] - depth[v];
        for (int i = 0; i < M; i++)
        {
            if (getBit(diff, i))
                u = dp[u][i];
        }

        if (u == v)
            return u;

        for (int i = M - 1; i >= 0; i--)
        {
            if (dp[u][i] != dp[v][i])
                u = dp[u][i], v = dp[v][i];
        }

        u = dp[u][0], v = dp[v][0];
        assert(u == v);
        return u;
    };

    // for (int i = 0; i < n; i++)
    //     print(i, adj[i], dp[i][0])

    int cycle = inf;

    std::fill(std::begin(vis), std::end(vis), 0);
    auto bfs = [&](int src)
    {
        vis[src] = 1;
        std::queue<int> q;
        q.emplace(src);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (int v : adj[u])
            {
                if (!vis[v])
                {
                    vis[v] = 1;
                    q.emplace(v);
                }
                else if (v != dp[u][0])
                {
                    // print(depth[u], depth[v], depth[lca(u,v)])
                    cycle = std::min(cycle, 1 + depth[u] + depth[v] - 2 * depth[lca(u, v)]);
                }
            }
        }
    };

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            bfs(i);
    }

    std::cout << (cycle == inf ? -1 : cycle) << "\n";
    
    return 0;
}