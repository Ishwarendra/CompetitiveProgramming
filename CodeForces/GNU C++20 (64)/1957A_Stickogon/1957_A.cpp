#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

/**
 * Make as many equilateral triangle as possible
 * Since it uses least number of sticks and increase poly count by 1
 */
void solve()
{
    int n;
    std::cin >> n;
    
    std::map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        m[x]++;
    }
    
    int ans = 0;
    for (auto &[_, f] : m)
        ans += f / 3;
    
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