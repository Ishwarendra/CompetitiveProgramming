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
    
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    auto f = [&](int start, int end, int max) -> i64
    {
        if (start > end)
            return 0LL;

        int n = end - start + 1;
        i64 ans = 1LL * n * (start + end) / 2;
        if (end > max)
            ans -= 1LL * (end - max) * (end - max + 1) / 2;

        return ans;
    };

    i64 ans = 0;
    for (int x = a; x <= b; x++)
    {
        int end = d - (x + b - 1);
        int start = std::max(1, d - (x + c - 1));
        ans += f(start, end, d - c + 1);
    }

    auto len = [&](int l, int r) -> i64
    {
        return r - l + 1LL;
    };

    ans = len(a, b) * len(b, c) * len(c, d) - ans;

    std::cout << ans;
    
    return 0;
}