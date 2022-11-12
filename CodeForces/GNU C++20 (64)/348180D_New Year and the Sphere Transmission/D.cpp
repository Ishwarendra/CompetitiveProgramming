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
    
    int n;
    std::cin >> n;

    std::set<i64> ans;

    auto f = [&](int d)
    {
        int terms = (n - 1) / d + 1;
        return 1LL * terms * (2LL + (terms - 1) * d) / 2;
    };

    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ans.emplace(f(std::gcd(n, i)));
            ans.emplace(f(std::gcd(n, n / i)));
        }
    }

    for (auto i : ans)
        std::cout << i << " ";
    
    return 0;
}