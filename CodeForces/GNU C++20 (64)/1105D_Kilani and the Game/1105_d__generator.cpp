#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
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
    // std::cout << t << "\n";

    while (t--)
    {
        int n = 200, m = 170, p = 5;
        std::cout << n << " " << m << " " << p << "\n";

        std::cout << "1 2 4 7 9\n";
        std::vector a(n, std::string(m, '.'));

        for (int i = 0; i < p; i++)
        {
            int x = get_rand(1, 3);
            while (x--)
            {
                int i1 = get_rand(1, n);
                int i2 = get_rand(1, m);
                a[i1 - 1][i2 - 1] = char(i + '1');
            }
        }

        for (int i = 0; i < n; i++)
            std::cout << a[i] << "\n";
    }
    
    return 0;
}