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
    
    int n, m, ta, tb, k;
    std::cin >> n >> m >> ta >> tb >> k;

    std::vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    for (int i = 0; i < m; i++)
        std::cin >> b[i];

    if (k >= std::min(n, m))
    {
        std::cout << -1;
        return 0;
    }

    constexpr int inf = std::numeric_limits<int>::max();
    int ans = b.front() + tb;

    for (int x = 0; x <= k; x++)
    {
        int id = std::lower_bound(std::begin(b), std::end(b), a[x] + ta) - std::begin(b);
        if (id + k - x >= m)
            ans = inf;
        else
            ans = std::max(ans, b[id + k - x] + tb);
    }

    std::cout << (ans == inf ? -1 : ans);
    
    return 0;
}