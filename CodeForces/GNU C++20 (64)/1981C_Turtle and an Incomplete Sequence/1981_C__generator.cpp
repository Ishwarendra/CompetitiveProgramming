#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

template<class T = int> 
T get_rand(T l, T r) 
{
    assert(l <= r);
    return std::uniform_int_distribution<T>(l, r)(rng);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t = 1;
    std::cout << t << "\n";

    while (t--)
    {
        int n = get_rand(4, 7);
        std::cout << n << "\n";
        
        std::vector<int> a(n);
        a[0] = get_rand(1, 7);
        for (int i = 1; i < n; i++)
        {
            int u = get_rand(0, 2);
            if (u == 0)
                a[i] = a[i - 1] / 2;
            else if (u == 1)
                a[i] = a[i - 1] * 2 + 1;
            else
                a[i] = a[i - 1] * 2;
        }
        
        std::cout << a[0] << " ";
        for (int i = 1; i < n - 1; i++)
            std::cout << "-1 ";
        std::cout << a.back();
    }
    
    return 0;
}