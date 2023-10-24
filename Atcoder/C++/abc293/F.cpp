#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    std::array<int, 3> f{}, s{};
    for (int i = 0; i < 3; i++)  
        std::cin >> f[i];
    for (int i = 0; i < 3; i++)
        std::cin >> s[i];

    int min = std::min(f[2], s[1]);
    int ans = 2 * min;
    f[2] -= min, s[1] -= min;

    min = std::min(f[1], s[0]);
    f[1] -= min, s[0] -= min;

    min = std::min(f[1], s[1]);
    f[1] -= min, s[1] -= min;

    min = std::min(f[2], s[2]);
    f[2] -= min, s[2] -= min;

    for (int i = 0; i < 3; i++)
    {
        min = std::min(f[0], s[i]);
        f[0] -= min, s[i] -= min;
    }

    ans -= 2 * f[1];

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