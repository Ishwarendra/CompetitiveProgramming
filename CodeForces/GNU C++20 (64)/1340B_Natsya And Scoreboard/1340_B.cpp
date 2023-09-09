#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::map<int, std::string> m;
    m[0] = "1110111", m[1] = "0010010", m[2] = "1011101";
    m[3] = "1011011", m[4] = "0111010", m[5] = "1101011";
    m[6] = "1101111", m[7] = "1010010", m[8] = "1111111";
    m[9] = "1111011";

    int n, k;
    std::cin >> n >> k;

    auto get = [&](std::string s, int dig)
    {
        auto t = m[dig];
        int ans = 0;

        for (int i = 0; i < 7; i++)
        {
            if (s[i] == '1' and t[i] == '0')
                return inf;
            ans += s[i] != t[i];
        }

        return ans;
    };

    std::vector<std::string> a(n);
    std::vector need(n, std::array<int, 10>());
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        for (int dig = 0; dig < 10; dig++)
            need[i][dig] = get(a[i], dig);
    }

    std::vector dp(n + 1, std::vector(k + 1, 0));
    dp[n][0] = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int rem = 0; rem <= k; rem++)
        {
            for (int cur = 0; cur < 10; cur++)
            {
                if (rem - need[i][cur] >= 0)
                    dp[i][rem] |= dp[i + 1][rem - need[i][cur]];
            }
        }
    }

    std::string ans;
    int rem = k;
    
    for (int i = 0; i < n; i++)
    {
        for (int dig = 9; dig >= 0; dig--)
        {
            if (rem - need[i][dig] < 0)
                continue;

            if (dp[i + 1][rem - need[i][dig]])
            {
                ans += char('0' + dig);
                rem -= need[i][dig];
                break;
            }
        }
    }

    if (std::size(ans) < n)
        std::cout << -1;
    else
        std::cout << ans;

    return 0;
}