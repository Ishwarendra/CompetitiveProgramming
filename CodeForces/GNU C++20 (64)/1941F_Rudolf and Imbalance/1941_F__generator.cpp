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
        int n = get_rand(2, 5), m = get_rand(1, 5), k = get_rand(1, 5);
        std::cout << n << " " << m << " " << k << "\n";

        int p = 0;
        for (int i = 0; i < n; i++)
        {
            int x = get_rand(1, 10);
            std::cout << p + x << " \n"[i == n - 1];
            p += x;
        }

        for (int i = 0; i < m; i++)
            std::cout << get_rand(1, 30) << " \n"[i == m - 1];
        for (int i = 0; i < k; i++)
            std::cout << get_rand(1, 30) << " \n"[i == k - 1];
    }
    
    return 0;
}