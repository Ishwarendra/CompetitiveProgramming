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
    
    int n, x;
    std::cin >> n >> x;

    std::vector<int> p;
    std::set<int> no {x};

    for (int i = 1; i < (1 << n); i++)
    {
        if (no.count(i))
            continue;

        p.emplace_back(i);
        no.emplace(i ^ x);
    }

    std::cout << std::ssize(p) << "\n";
    for (int i = 0; i < std::ssize(p); i++)
    {
        if (i == 0)
            std::cout << p[i] << " \n"[i == std::ssize(p) - 1];
        else
            std::cout << (p[i] ^ p[i - 1]) << " \n"[i == std::ssize(p) - 1];
    }
    
    return 0;
}