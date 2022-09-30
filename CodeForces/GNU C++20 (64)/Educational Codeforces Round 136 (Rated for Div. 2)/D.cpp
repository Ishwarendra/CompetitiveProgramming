#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> adj[n], p(n);
    for (int i = 1; i < n; ++i)  
    {
        std::cin >> p[i];
        p[i]--;

        adj[p[i]].emplace_back(i);
    }
    
    int left = 1, right = n;
    int ans = -1;

    auto good = [&](int mid)
    {
        std::vector<int> h(n);
        int moves = 0;
        // leaves will have higher value since p_i < i
        for (int i = n - 1; i > 0; i--)
        {
            if (h[i] + 1 == mid and p[i] != 0) 
                moves++;
            else
                h[p[i]] = std::max(h[p[i]], h[i] + 1);
        }
        print(h, moves)
        return moves <= k;
    }; 
    
    while (left <= right)
    {
        int mid = (left + right) >> 1;

        if (good(mid))
            ans = mid, right = mid - 1;
        else
            left = mid + 1;
    }

    std::cout << ans << "\n";
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