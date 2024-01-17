#include "bits/stdc++.h"

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

    std::vector a(n, std::array<int, 2>());
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
            std::cin >> a[j][i];
    }

    for (int i = 1; i < n; i++)
        a[i][0] += a[i - 1][0];

    std::vector<int> pmax(n);
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            pmax[i] = a[i][1];
        else
            pmax[i] = std::max(pmax[i - 1], a[i][1]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (i >= k)
            break;

        int cur = a[i][0];
        int max = pmax[i];

        cur += (k - 1 - i) * max;
        ans = std::max(ans, cur);
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