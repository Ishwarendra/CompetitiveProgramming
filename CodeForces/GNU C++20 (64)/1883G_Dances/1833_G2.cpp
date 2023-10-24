#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n - 1), b(n);
    for (int i = 0; i < n - 1; i++)  
        std::cin >> a[i];
    for (int i = 0; i < n; i++)
        std::cin >> b[i];

    std::sort(std::begin(a), std::end(a));
    std::sort(std::begin(b), std::end(b));

    int skip = 0;
    int max_skipped = 0;
    int i = 0, j = 0;
    while (i < n - 1)
    {
        while (j < n and a[i] >= b[j])
        {
            max_skipped = std::max(max_skipped, b[j]);
            j++, skip++;
        }

        if (j < n)
            j++;
        i++;
    }

    while (j < n)
    {
        max_skipped = std::max(max_skipped, b[j]);
        j++, skip++;
    }

    i64 ans = 1LL * m * (skip - 1);
    ans += std::max(0, m - max_skipped + 1);

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