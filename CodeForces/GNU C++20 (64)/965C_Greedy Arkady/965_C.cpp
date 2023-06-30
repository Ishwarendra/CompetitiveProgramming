#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;
using i128 = __int128;
using u128 = __uint128_t;

std::ostream &operator<<(std::ostream &os, i128 n) 
{
    std::string s;
    do
    {
        s += '0' + n % 10;
        n /= 10;
    } while (n);
    std::reverse(std::begin(s), std::end(s));
    return os << s;
}

constexpr int N = 1e4;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    i64 n, k, M, D;
    std::cin >> n >> k >> M >> D;

    i128 ans = M;
    if (ans * k < n)
        ans = 0;

    auto pos = [&](i128 mid)
    {
        return (n - mid) / (k * mid) + 1;
    };

    for (int d = 2; d <= D; d++)
    {
        i128 left = 1, right = M;
        while (left <= right)
        {
            i128 mid = (left + right) / 2;
            int have = pos(mid);
            if (have == d)
                ans = std::max(ans, mid * d), left = mid + 1;
            else if (have > d)
                left = mid + 1;
            else
                right = mid - 1;
        }
    }

    std::cout << ans;
    
    return 0;
}