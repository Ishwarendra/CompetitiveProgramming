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
    i64 k;
    std::cin >> n >> k;

    std::vector<i64> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    if (a.back() == a.front())
    {
        std::cout << (k == a[0] ? "YES\n" : "NO\n");
        return;
    }

    i64 g = 0;
    for (int i = 1; i < n; i++)
        g = std::gcd(g, a[i] - a[0]);
    
    if (std::abs(k - a[0]) % g == 0)
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
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