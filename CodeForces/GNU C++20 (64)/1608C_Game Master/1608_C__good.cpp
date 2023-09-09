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
    std::cin >> n;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    for (int i = 0; i < n; i++)
        std::cin >> b[i];

    std::string ans(n, '1');
    for (int i = 0; i < n; i++)
    {   
        std::queue<int> q;
        std::vector<int> vis(n, 0);
        for (int j = 0; j < n; j++)
        {
            if (a[i] >= a[j])
                vis[j] = 1, q.emplace(j);
        }

        while (!q.empty())
        {
            auto u = q.front();
            q.pop();

            for (int j = 0; j < n; j++)
            {
                if (b[u] > b[j])
                    vis[j] = 1;
            }
        }

        if (std::accumulate(std::begin(vis), std::end(vis), 0) != n)
            ans[i] = '0';
    }

    std::cout << ans << "\n";
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