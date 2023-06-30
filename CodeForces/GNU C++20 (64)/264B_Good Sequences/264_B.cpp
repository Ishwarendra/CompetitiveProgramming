#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

std::vector<int> minPrime(const int n)
{
    std::vector<int> min_prime(n);
    std::iota(std::begin(min_prime), std::end(min_prime), 0);

    for (int i = 2; i * i < n; i++)
    {
        if (min_prime[i] != i)
            continue;
        for (int j = i * i; j < n; j += i)
            min_prime[j] = std::min(min_prime[j], i);
    }

    return min_prime;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto min_prime = minPrime(1e5 + 2);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    if (n == 1)
    {
        std::cout << "1\n";
        return 0;
    }

    auto primeFactors = [&](int x)
    {
        std::map<int, int> m;
        while (x > 1)
        {
            m[min_prime[x]]++;
            x /= min_prime[x];
        }

        return m;
    };

    std::map<int, int> best;
    std::vector<int> dp(n);
    for (int i = 0; i < n; i++)
    {
        auto pfs = primeFactors(a[i]);
        for (auto [pf, _] : pfs)
        {
            if (best.contains(pf))
                dp[i] = std::max(dp[i], best[pf] + 1);
            else
                dp[i] = std::max(dp[i], 1);
        }

        for (auto [pf, _] : pfs)
            best[pf] = std::max(best[pf], dp[i]);
    }
    
    std::cout << *std::max_element(std::begin(dp), std::end(dp));

    return 0;
}