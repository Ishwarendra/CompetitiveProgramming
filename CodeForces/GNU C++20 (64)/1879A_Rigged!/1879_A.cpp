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

    std::vector a(n, std::array<int, 2>());
    for (auto &[s, e] : a)  
        std::cin >> s >> e;

    int max = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i][0] >= a[0][0])
            max = std::max(max, a[i][1]);
    }
    
    std::cout << (a[0][1] > max ? a[0][0] : -1) << "\n";
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