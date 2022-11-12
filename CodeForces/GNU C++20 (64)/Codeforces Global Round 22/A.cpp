#include <bits/stdc++.h>

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

    std::vector<int> a(n), b, c;
    for (int i = 0; i < n; ++i)  
        std::cin >> a[i];

    for (int i = 0; i < n; ++i)
    {
        int x;
        std::cin >> x;

        (a[i] ? b : c).push_back(x);
    }

    std::sort(std::rbegin(b), std::rend(b));
    std::sort(std::rbegin(c), std::rend(c));

    i64 ans = 0;
    int i = 0, j = 0;
    n = std::size(b);
    int m = std::size(c);

    while (i < n and j < m)
        ans += 2LL * b[i++] + 2LL * c[j++];
    while (i < n)
        ans += b[i++];
    while (j < m)
        ans += c[j++];

    if (n == m)
        ans -= std::min(b.back(), c.back());

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