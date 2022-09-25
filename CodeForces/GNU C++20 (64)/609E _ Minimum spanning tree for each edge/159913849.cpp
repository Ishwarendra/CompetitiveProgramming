#include <bits/stdc++.h>
 
#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif
 
class DSU
{
    std::vector<int> rnk, par;
public:
    DSU(int n) : rnk(n, 1), par(n)
    {
        std::iota(par.begin(), par.end(), 0);
    }
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
 
const int M = 20;
 
std::vector<std::tuple<int, int, int>> edges, kedge;
std::vector<std::pair<int, int>> *adj;
std::vector<int> depth;
std::vector<int> up[M], max[M];
 
void dfs(int u, int par, std::vector<int> &mark, int w)
{
    depth[u] = depth[par] + 1;
    up[0][u] = par;
    max[0][u] = w;
    mark[u] = 1;
 
    for (auto [nb, wt] : adj[u])
        if (not mark[nb])
            dfs(nb, u, mark, wt);
}
 
void sparse_init()
{
    for (int i = 1; i < M; ++i)
    {
        for (int j = 1; j < up[i].size(); ++j)
        {
            up[i][j] = up[i - 1][up[i - 1][j]];
            max[i][j] = std::max(max[i - 1][j], max[i - 1][up[i - 1][j]]);
        }
    }
}
 
int get(int u, int v)
{
    if (depth[u] < depth[v])
        std::swap(u, v);
 
    int diff = depth[u] - depth[v];
    int ans = 0;
 
    for (int i = M - 1; i >= 0; --i)
    {
        if ((diff >> i) & 1)
            ans = std::max(ans, max[i][u]), u = up[i][u];
    }
 
    // Now at same depth
    if (u == v)
        return ans;
 
    for (int i = M - 1; i >= 0; --i)
    {
        if (up[i][u] != up[i][v])
        {
            ans = std::max({ans, max[i][u], max[i][v]});
            u = up[i][u];
            v = up[i][v];
        }
    }
 
    return std::max({ans, max[0][u], max[0][v]});
}
 
void solve()
{
    int n, m;
    std::cin >> n >> m;
 
    adj = new std::vector<std::pair<int, int>>[n + 1];
    depth.resize(n);
    for (int i = 0; i <= M; ++i)
        up[i].resize(n), max[i].resize(n);
 
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
 
        edges.push_back(std::tuple<int, int, int>(u, v, w));
        kedge.push_back(std::tuple<int, int, int>(w, u, v));
    }
 
    std::sort(kedge.begin(), kedge.end());
 
    DSU d(n);
    long long mst_cost = 0LL;
 
    for (auto [w, u, v] : kedge)
    {
        if (d.unite(u, v))
        {
            mst_cost += w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
    }
 
    std::vector<int> mark(n);
    dfs(0, 0, mark, 0);
    sparse_init();
 
    for (auto [u, v, w] : edges)
        std::cout << mst_cost + w - get(u, v) << "\n";
}
 
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int t = 1;
 
    while (t--)
        solve();
 
    return 0;
}