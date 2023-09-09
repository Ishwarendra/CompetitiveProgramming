#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    std::vector<i64> p1, p2;

    for (int i = 0; i < n; i++)
    {
        int b;
        std::cin >> b;
        (b == 1 ? p1 : p2).emplace_back(a[i]);
    }

    int ans = inf;
    std::sort(std::rbegin(p1), std::rend(p1));
    std::sort(std::rbegin(p2), std::rend(p2));

    for (int i = 1; i < std::size(p1); i++)
        p1[i] += p1[i - 1];
    for (int i = 1; i < std::size(p2); i++)
        p2[i] += p2[i - 1];

    for (int i = 0, sum = 0; i < std::size(p2); i++)
    {
        if (p2[i] >= m)
        {
            ans = 2 * (i + 1);
            break;
        }
    }

    for (int i = 0; i < std::size(p1); i++)
    {
        i64 need = m - p1[i];
        if (need <= 0)
            ans = std::min(ans, i + 1);
        else
        {
            int id = std::lower_bound(std::begin(p2), std::end(p2), need) - std::begin(p2);
            if (id != std::size(p2))
                ans = std::min(ans, i + 1 + 2 * (id + 1));
        }
    }

    std::cout << (ans < inf ? ans : -1) << "\n";
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