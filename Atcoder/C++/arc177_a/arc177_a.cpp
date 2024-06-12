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
    
    std::array<int, 6> den{}, val {1, 5, 10, 50, 100, 500};
    for (int i = 0; i < 6; i++)
        std::cin >> den[i];

    
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    
    std::sort(std::rbegin(a), std::rend(a));
    for (auto x : a)
    {
        for (int i = 5; i >= 0; i--)
        {
            int need = x / val[i];
            if (need == 0)
                continue;
            
            int sub = std::min(need, den[i]);
            den[i] -= sub;
            x -= sub * val[i];
        }
        
        if (x != 0)
        {
            std::cout << "No";
            return 0;
        }
    }
    
    std::cout << "Yes";
    
    return 0;
}