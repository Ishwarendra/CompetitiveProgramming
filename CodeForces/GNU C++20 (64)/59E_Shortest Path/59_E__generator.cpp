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

    while (t--)
    {
        int n = get_rand(4, 6);
        int m = get_rand(n + 1, n + 2);
        int k = get_rand(1, 3);

        std::cout << n << " " << m << " " << k << "\n";
        std::map<std::pair<int, int>, bool> done;
        int sz = 1;
        for (int i = 0; i < n - 1; i++)
        {
            int v = get_rand(1, sz);
            std::cout << sz + 1 << " " << v << "\n";
            sz++;
            done[{sz, v}] = done[{v, sz}] = 1;
        }

        for (int i = n - 1; i < m; i++)
        {
            int u = 0, v = 0;
            while (u == v || done.contains({u, v}))
            {
                u = get_rand(1, n);
                v = get_rand(1, n);
            }
            std::cout << u << " " << v << "\n";
            done[{u, v}] = done[{v, u}] = 1;
        }

        std::set<std::array<int, 3>> s;
        while (std::size(s) < k)
        {   
            std::array<int, 3> a;
            for (int i = 0; i < 3; i++)
                a[i] = get_rand(1, n);
            s.emplace(a);
        }

        for (auto &[a, b, c] : s)
            std::cout << a << " " << b << " " << c << "\n";
    }
    
    return 0;
}