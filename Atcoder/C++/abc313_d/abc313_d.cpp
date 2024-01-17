#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;

    if (k == 1)
    {
        std::vector<int> a;
        for (int i = 0; i < n; i++)
        {
            std::cout << "? " << i + 1 << std::endl;
            int p;
            std::cin >> p;
            a.emplace_back(p);
        }

        std::cout << "! ";
        for (int i = 0; i < n; i++)
            std::cout << a[i] << " ";
        std::cout << std::endl;

        return 0;
    }

    std::vector a(n, -1);
    int flip = 0;

    std::set<int> s;
    for (int i = 1; i < k; i++)
        s.emplace(i);

    auto query = [&](int id)
    {
        s.emplace(id);

        std::cout << "? ";
        for (int x : s)
            std::cout << x + 1 << " ";
        std::cout << std::endl;

        s.erase(id);

        int p;
        std::cin >> p;
        return p;
    };

    a[0] = query(0);
    for (int i = k; i < n; i++)
        a[i] = query(i);

    s.emplace(k);
    for (int i = 1; i < k; i++)
    {
        s.erase(i);
        a[i] = (a[k] ^ query(0)) ? 1 - a[0] : a[0];
        s.emplace(i);
    }

    int p = 0;
    for (int i = 0; i < k; i++)
        p ^= a[i];
    flip = p ^ a[0];

    std::cout << "! ";
    for (int i = 0; i < n; i++)
        std::cout << (a[i] ^ flip) << " ";
    std::cout << std::endl;
    
    return 0;
}