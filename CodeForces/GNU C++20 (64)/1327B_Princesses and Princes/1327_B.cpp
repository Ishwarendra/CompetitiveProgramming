#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;
    
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n; i++)
    {
        int len;
        std::cin >> len;
        
        for (int j = 0; j < len; j++)
        {
            int v;
            std::cin >> v;
            adj[i].emplace_back(v - 1);
        }
    }
    
    std::vector<int> done(n);
    int miss = -1;
    for (int i = 0; i < n; i++)
    {
        int ok = 0;
        for (int j : adj[i])
        {
            if (!done[j])
            {
                ok = 1;
                done[j] = 1;
                break;
            }
        }
        
        if (!ok)
            miss = i;
    }
    
    if (miss == -1)
        std::cout << "OPTIMAL\n";
    else
    {
        std::cout << "IMPROVE\n";
        for (int i = 0; i < n; i++)
        {
            if (!done[i])
            {
                std::cout << miss + 1 << " " << i + 1 << "\n";
                break;
            }
        }
    }  
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