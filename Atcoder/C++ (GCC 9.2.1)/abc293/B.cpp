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
    
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::vector<int> vis(n);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            vis[a[i] - 1] = 1;
    }

    int tot = n - std::accumulate(std::begin(vis), std::end(vis), 0);
    std::cout << tot << "\n";
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            std::cout << i + 1 << " ";
    }

    return 0;
}