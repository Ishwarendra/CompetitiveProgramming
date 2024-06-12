#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

/**
 * WLOG a[i] < a[j]
 * a[i] % a[j] = a[i]
 * a[j] % a[i] < a[i]
 * Thus if a[i] % a[j] will be bigger than a[j] % a[i] if a[i] < a[j]
 * We know two things, a[j] > a[i] and the value of a[i] in 2 queries
 * We can find out all a[i] in 2 * n queries except 1 (which can be found by finding the missing number)
 */

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    auto query = [&](int i, int j)
    {
        std::cout << "? " << i + 1 << " " << j + 1 << std::endl;  
        int r;
        std::cin >> r;
        return r;
    };
    
    std::vector<int> a(n);
    int max = 0, xr = n;
    for (int i = 1; i < n; i++)
    {
        xr ^= i;
        auto r1 = query(max, i);
        auto r2 = query(i, max);
        
        if (r1 > r2)
        {
            a[max] = r1;
            max = i;    
        }
        else
            a[i] = r2;
    }
    
    for (int i = 0; i < n; i++)
        xr ^= a[i];
    
    for (int i = 0; i < n; i++)    
    {
        if (a[i] == 0)
            a[i] = xr;
    }
    
    std::cout << "! ";
    for (int i = 0; i < n; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;
    
    return 0;
}