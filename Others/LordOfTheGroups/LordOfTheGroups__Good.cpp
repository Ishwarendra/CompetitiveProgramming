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
    
    int t;
    std::cin >> t;
    
    int n, d;
    std::cin >> n >> d;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    
    auto getBit = [&](int x, int pos) { return x >> pos & 1; };
    int ans = 0;
    for (int mask = 0; mask < (1 << n); mask++)
    {
        std::vector<int> b;
        for (int i = 0; i < n; i++)
        {
            if (getBit(mask, i))
                b.emplace_back(a[i]);
        }
        
        std::sort(std::begin(b), std::end(b));
        
        int add = 1;
        for (int i = 0; i < std::size(b); i++)
        {
            for (int j = i + 1; j < std::size(b); j++)
            {
                int ok = 0;
                for (int dx = -d; dx <= d; dx++)
                {
                    if (std::binary_search(std::begin(b), std::end(b), b[i] + b[j] + dx))
                        ok = 1;
                }
                
                if (!ok)
                    add = 0;
            }
        }
        
        if (std::size(b) > 1 and add)
        {
            ans += add;
            // print(b)
        }
    }
    
    std::cout << ans << "\n";
    
    return 0;
}