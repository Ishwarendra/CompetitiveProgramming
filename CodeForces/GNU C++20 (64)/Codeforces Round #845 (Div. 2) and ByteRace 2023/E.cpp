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

    i64 max = 0, min = 0, sum = 0;
    for (int i = 0; i < n; i++)  
    {
        int x;
        std::cin >> x;
        sum += x;

        max = std::max(max, sum);
        min = std::min(min, sum);
    }

    std::cout << max - min << "\n";
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