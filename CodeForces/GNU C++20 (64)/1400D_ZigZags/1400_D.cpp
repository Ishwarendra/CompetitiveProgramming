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

    std::vector<int> a(n);
    std::vector m(n, std::vector(n, 0)), f(n, std::vector(n, 0));

    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        a[i]--;
        m[a[i]][i]++;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
            m[i][j] += m[i][j - 1];
    }

    i64 ans = 0;
    for (int j = n - 1; j > 0; j--)
    {
        for (int c = 0; c < n; c++)
            ans += 1LL * m[c][j - 1] * f[c][a[j]];

        for (int k = j + 1; k < n; k++)
            f[a[j]][a[k]]++;
    }

    std::cout << ans << '\n';
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