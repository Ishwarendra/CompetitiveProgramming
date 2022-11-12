#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int l, r, k;
    std::cin >> l >> r >> k;

    if (l == r)
    {
        std::cout << (l == 1 ? "NO\n" : "YES\n");
        return;
    }

    // 1 2 3 4 5 -> 3 op
    // 2 3 4 5 6 -> 2 op
    // 2 3 4 5 -> 2 op
    // 3 4 5 6 -> 2 op

    int odd = (r - l + 1) / 2;
    if (l % 2 == 1 and (r - l + 1) & 1)
        odd++;
    
    if (k >= odd)  
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
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