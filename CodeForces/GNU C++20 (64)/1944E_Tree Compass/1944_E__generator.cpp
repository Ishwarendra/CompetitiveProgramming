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
        int n = 10;
        std::cout << n << "\n";

        int sz = 1;
        for (int i = 1; i < n; i++)
        {
            std::cout << i + 1 << " " << get_rand(1, sz) << "\n";
            sz++;
        }
    }
    
    return 0;
}