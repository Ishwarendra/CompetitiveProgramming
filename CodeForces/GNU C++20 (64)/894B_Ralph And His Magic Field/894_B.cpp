#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int MOD = 1e9 + 7;

int power(int a, i64 b)
{
    int ans = 1;
    for (; b; b /= 2, a = (1LL * a * a) % MOD)
    {
        if (b & 1)
            ans = (1LL * ans * a) % MOD;
    }

    return ans;
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    i64 n, m;
    int k;
    std::cin >> n >> m >> k;

    n %= (MOD - 1);
    m %= (MOD - 1);
    auto sub = [&](int a, int x)
    {
        a -= x;
        if (a < 0)
            a += MOD - 1;
        return a;
    };

    if (k == -1 and n % 2 != m % 2)
        std::cout << 0;
    else
        std::cout << power(2, 1LL * sub(n, 1) * sub(m, 1));
    
    return 0;
}