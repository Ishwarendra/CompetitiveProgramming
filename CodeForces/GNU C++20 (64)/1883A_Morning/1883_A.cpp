#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int prev = 1;
    int ans = 0;
    for (int i = 0; i < 4; i++)
    {
        char ch;
        std::cin >> ch;
        int cur = ch - '0';
        if (cur == 0)
            cur = 10;

        ans += std::abs(prev - cur) + 1;
        prev = cur;
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