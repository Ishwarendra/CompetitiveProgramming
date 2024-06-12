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
    
    int t = 20;
    std::cout << t << "\n";

    while (t--)
    {
        int n = get_rand(0, 100);
        int m = get_rand(0, 100);
        std::cout << n << " " << m << "\n";
    }
    
    return 0;
}