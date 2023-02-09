#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    i64 n;
    int s;
    std::cin >> n >> s;

    auto getSum = [&](auto x)  
    {
        int sum = 0;
        while (x)
        {
            sum += x % 10;
            x /= 10;
        }

        return sum;
    };

    if (getSum(n) <= s)
    {
        std::cout << "0\n";
        return;
    }

    i64 cur = 1;
    i64 ans = 0;

    while (getSum(n) > s)
    {
        i64 cur_digit = (n % (cur * 10)) / cur;
        ans += (10 - cur_digit) * cur;
        n += (10 - cur_digit) * cur;
        cur *= 10;
    }

    std::cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}