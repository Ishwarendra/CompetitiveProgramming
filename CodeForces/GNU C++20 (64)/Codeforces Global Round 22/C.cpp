#include <bits/stdc++.h>

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

    constexpr int N = 101;

    int dp[N][N][2]{};
    std::memset(dp, -1, sizeof dp);

    std::function<int(int, int, int)> f = [&](int even, int odd, int sum) -> int
    {
        if (even == 0 or odd == 0)
        {
            if (odd == 0)
                return sum == 0;
            else 
            {
                // 1,2 5,6 9,10
                if (((odd + 1) / 2) % 2)
                    return sum == 1;
                else
                    return sum == 0;
            }
        }

        if (dp[even][odd][sum] != -1)
            return dp[even][odd][sum];

        int &cur = dp[even][odd][sum];
        cur = 0;
        int left = f(even - 1, odd - 1, sum);
        if (even - 2 >= 0)
            left &= f(even - 2, odd, sum);

        int right = f(even - 1, odd - 1, sum ^ 1);
        if (odd - 2 >= 0)
            right &= f(even, odd - 2, sum ^ 1);

        
        return cur = left | right; 
    };

    int t;
    std::cin >> t;

    while (t--)
    {
        int n;
        std::cin >> n;

        int one = 0, zero = 0;
        for (int i = 0; i < n; ++i)
        {
            int x;
            std::cin >> x;

            x = (x % 2 + 2) % 2;
            one += x == 1;
            zero += x == 0;
        }
        bool alice = f(zero, one, 0);
        std::cout << (alice ? "Alice" : "Bob") << "\n";
    }

    return 0;
}