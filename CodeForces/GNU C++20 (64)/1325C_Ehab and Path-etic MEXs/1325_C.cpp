#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

/**
 * If any node has degree greater than 2 then we can always assign 0,1,2
 * in a way such that mex <= 2 for all paths
 * If all nodes have degree atmost 2??
 * will be linear
 */

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<std::vector<int>> adj(n);
    std::map<std::pair<int, int>, int> pos;
    std::vector<int> deg(n);
    
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
        pos[{u, v}] = pos[{v, u}] = i;
        deg[u]++, deg[v]++;
    }
    
    int root = 0;
    for (int i = 0; i < n; i++)
    {
        if (deg[root] < deg[i])
            root = i;
    }
    
    std::vector<int> ans(n - 1, -1);
    int num = 0;
    for (int u : adj[root])
        ans[pos[{u, root}]] = num++;
    
    for (int i = 0; i < n - 1; i++)
    {
        if (ans[i] == -1)
            ans[i] = num++;
    }
    
    for (int i = 0; i < n - 1; i++)
        std::cout << ans[i] << "\n";
    
    return 0;
}