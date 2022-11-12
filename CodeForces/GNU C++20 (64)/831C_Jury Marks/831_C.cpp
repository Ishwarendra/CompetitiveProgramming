#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

struct custom_hash 
{
    static uint64_t splitmix64(uint64_t x) 
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const 
    {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    template<typename L, typename R>
    size_t operator()(std::pair<L,R> const& Y) const
    {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(Y.first * 31ull + Y.second + FIXED_RANDOM);
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> k >> n;

    std::vector<i64> a(k), b(n);
    for (int i = 0; i < k; ++i)
        std::cin >> a[i];
    for (int i = 0; i < n; ++i)
        std::cin >> b[i];

    auto p = a;
    for (int i = 1; i < k; ++i)
        p[i] += p[i - 1];

    std::sort(std::begin(p), std::end(p));

    auto check = [&](i64 x)
    {
        for (int b_ : b)
        {
            // x + p = b_
            if (!std::binary_search(std::begin(p), std::end(p), b_ - x))
                return false;
        }

        return true;
    };

    std::unordered_set<i64, custom_hash> checked;

    int ans = 0;
    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            i64 x = b[j] - p[i];
            if (!checked.count(x))
            {
                checked.emplace(x);
                ans += check(x);
            }
        }
    }

    std::cout << ans;
    return 0;
}