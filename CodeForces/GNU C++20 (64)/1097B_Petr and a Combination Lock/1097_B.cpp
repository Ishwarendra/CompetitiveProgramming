#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
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
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    
    auto getBit = [&](int x, int pos) { return x >> pos & 1; };
    for (int mask = 0; mask < (1 << n); mask++)
    {
        int p = 0;
        for (int i = 0; i < n; i++)
        {
            if (getBit(mask, i))
                p = (p + a[i]) % 360;
            else
                p = (p - a[i] + 360) % 360;
        }
        
        if (p == 0)
        {
            std::cout << "YES\n";
            return 0;
        }
    }
    
    std::cout << "NO\n";
        
    return 0;
}