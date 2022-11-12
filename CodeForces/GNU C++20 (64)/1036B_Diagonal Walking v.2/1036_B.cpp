#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    i64 n, m, k;
    std::cin >> n >> m >> k;

    i64 s = std::max(n, m);
    i64 ans = s - 1;
    i64 rem = k - ans;

    if (k < s)
        ans = -1;
    else if (std::abs(m - n) % 2 == 1)
        ans += rem - 1;
    else
    {
        if (rem % 2 == 0)
            ans += rem - 2;
        else
            ans += rem;
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