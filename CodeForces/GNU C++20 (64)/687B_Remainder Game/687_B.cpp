#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;

    const int MOD = k;

    std::vector<int> c(n);
    for (int i = 0; i < n; i++)
        std::cin >> c[i];

    i64 lcm = 1;
    for (int i = 0; i < n; i++)
    {
        lcm = std::lcm<i64>(lcm, c[i]) % MOD;
        if (lcm == 0)
            break;
    }

    std::cout << (lcm ? "No\n" : "Yes\n");
    
    return 0;
}