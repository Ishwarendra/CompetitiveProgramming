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

    std::vector<std::array<int, 2>> a(n, {0, 0});
    i64 ans = 0;
    for (auto &[x, y] : a)
    {
        std::cin >> x >> y;
        if (x < y)
            std::swap(x, y);

        ans += 2 * y;
    }

    std::sort(std::begin(a), std::end(a));
    ans += a[0][0];
    for (int i = 0; i < n - 1; i++)    
        ans += (a[i + 1][0] - a[i][0]);
    ans += a[n - 1][0];

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