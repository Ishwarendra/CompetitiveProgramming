#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

class DSU
{
    std::vector<int> rnk, par;
public:
    DSU() {}
    DSU(int n) : rnk(n, 1), par(n) { std::iota(par.begin(), par.end(), 0); }
    int get(int x)
    {
        while (x != par[x]) x = par[x] = par[par[x]];
        return x;
    }
    bool unite(int x, int y)
    {
        int p1 = get(x), p2 = get(y);
        if (p1 == p2)
            return false;
        else
        {
            if (rnk[p2] > rnk[p1])
                std::swap(p1, p2);
                
            par[p2] = p1, rnk[p1] += rnk[p2], rnk[p2] = 0;                
            return true;
        }
    }
    bool same(int x, int y)
    {
        return get(x) == get(y);
    }
    int size(int x)
    {
        return rnk[get(x)];
    }
}; 

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    bool all_eq = true;

    std::vector a(n, std::string(m, '.'));
    DSU dsu(n + m);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        all_eq &= std::count(std::begin(a[i]), std::end(a[i]), '=') == m;
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '=')
                dsu.unite(i, j + n);
        }
    }

    if (all_eq)
    {
        std::cout << "Yes\n";
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < (i ? m : n); j++)
                std::cout << 1 << " \n"[j == m - 1];
        }

        return 0;
    }


    std::vector<std::set<int>> adj(n + m);
    std::vector<int> indeg(n + m);

    auto in = [&](int x, int y)
    {
        return adj[dsu.get(x)].count(dsu.get(y));
    };

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '>')
            {
                if (in(j + n, i))
                    continue;

                adj[dsu.get(j + n)].emplace(dsu.get(i));
                indeg[dsu.get(i)]++;
            }
            else if (a[i][j] == '<')
            {
                if (in(i, j + n))
                    continue;

                adj[dsu.get(i)].emplace(dsu.get(j + n));
                indeg[dsu.get(j + n)]++;
            }
        }
    }

    std::vector<int> ans(n + m);

    std::queue<int> q;
    for (int i = 0; i < n + m; i++)
    {
        if (indeg[dsu.get(i)] == 0 and ans[dsu.get(i)] != 1)
        {
            ans[dsu.get(i)] = 1;
            q.emplace(dsu.get(i));
        }
    }

    while (!q.empty())
    {
        auto u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            indeg[v]--;
            if (indeg[v] == 0)
            {
                ans[v] = std::max(ans[v], ans[u] + 1);
                q.emplace(v);
            }
        }
    }

    for (int id1 = 0; id1 < n; id1++)
    {
        for (int id2 = 0; id2 < m; id2++)
        {
            int i = dsu.get(id1);
            int j = dsu.get(id2 + n);

            if (ans[i] == 0 || ans[j] == 0)
            {
                std::cout << "No";
                return 0;
            }

            if (a[id1][id2] == '>' and ans[i] <= ans[j])
            {
                std::cout << "No";
                return 0;
            }

            if (a[id1][id2] == '<' and ans[i] >= ans[j])
            {
                std::cout << "No";
                return 0;
            }

            if (a[id1][id2] == '=' and ans[i] != ans[j])
            {
                std::cout << "No";
                return 0;
            }
        }
    }

    std::cout << "Yes\n";
    for (int i = 0; i < n + m; i++)
        std::cout << ans[dsu.get(i)] << " \n"[i == n - 1 || i == n + m - 1];

    return 0;
}