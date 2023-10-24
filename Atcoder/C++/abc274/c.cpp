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
    
    int n;
    std::cin >> n;

    std::map<int, int> h;

    h[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        std::cin >> x;
        
        h[i << 1] = h[x] + 1;
        h[i << 1 | 1] = h[x] + 1;
    }

    for (int i = 1; i <= 2 * n + 1; i++)
        std::cout << h[i] << "\n";
    
    return 0;
}