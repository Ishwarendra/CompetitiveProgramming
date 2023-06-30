#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::string s;
    std::cin >> n >> s;

    std::vector<std::vector<int>> adj(n);
    std::vector<int> indeg(n);
    for (int i = 0; i < n - 1; i++)  
    {
        int u = i, v = i + 1;
        if (s[i] == '>')
            std::swap(u, v);

        adj[u].emplace_back(v);
        indeg[v]++;
    }

    auto get = [&](std::vector<int> indeg, int max)
    {
        std::set<int> q;
        for (int i = 0; i < n; i++)
        {
            if (indeg[i] == 0)
                q.insert(max ? i : -i);
        }

        int num = 1;
        std::vector<int> ans(n);
        while (!q.empty())        
        {
            int u = *std::begin(q);
            q.erase(std::begin(q));
            u = max ? u : -u;

            ans[u] = num++;

            for (int v : adj[u])
            {
                indeg[v]--;
                if (indeg[v] == 0)
                    q.insert(max ? v : -v);
            }
        }

        return ans;
    };

    auto min = get(indeg, 0);
    auto max = get(indeg, 1);
    
    for (int i = 0; i < n; i++)
        std::cout << min[i] << " \n"[i == n - 1];
    for (int i = 0; i < n; i++)
        std::cout << max[i] << " \n"[i == n - 1];
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}