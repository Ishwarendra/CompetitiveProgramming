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

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += std::abs(a[i] - b[i]);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::swap(b[i], b[j]);

            int cur = 0;
            for (int k = 0; k < n; k++)
                cur += std::abs(a[k] - b[k]);
            // print(i, j, cur)
            ans = std::min(ans, cur);
            std::swap(b[i], b[j]);
        }
    }

    std::cout << ans << "\n";
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