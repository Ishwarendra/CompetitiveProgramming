#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int a, b;
    std::cin >> a >> b;
    
    a = std::abs(a), b = std::abs(b);
    int ans = std::min(a, b);

    a -= ans;
    b -= ans;
    if (a == 0)
        std::swap(a, b);

    ans *= 2;
    if (a == 0)
        std::cout << ans << "\n";
    else
    {
        ans += 2 * a - 1;
        std::cout << ans << "\n";
    }
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