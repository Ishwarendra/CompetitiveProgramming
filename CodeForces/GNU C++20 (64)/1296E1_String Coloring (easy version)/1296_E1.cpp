#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

/**
 * Two elements of same element will remain in same order always.
 * Divide string into two subsequence such that both of them are sorted.
 * dp[i][last_1][last_2] = (false/true): processing i-th character such that last element of
 * subsequences are last_1 and last_2 respectively. Either take or not take current character
 * If you take update last_1 else update last_2
 */

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::string s;
    std::cin >> n >> s;

    std::vector dp(n + 1, std::vector(26, std::array<int, 26>()));
    std::vector par(n + 1, std::vector(26, std::vector(26, std::pair<int, int>())));
    dp[0][0][0] = 1;
    
    for (int i = 1; i <= n; i++)
    {
        int cur = s[i - 1] - 'a';
        for (int last_1 = 0; last_1 < 26; last_1++)
        {
            for (int last_2 = 0; last_2 < 26; last_2++)
            {
                if (dp[i - 1][last_1][last_2] == 0)
                    continue;
                
                if (last_1 <= cur)
                {
                    dp[i][cur][last_2] = 1;
                    par[i][cur][last_2] = {last_1, last_2};
                }
                
                if (last_2 <= cur)
                {
                    dp[i][last_1][cur] = 1;
                    par[i][last_1][cur] = {last_1, last_2};                    
                }
            }
        }
    }
    
    int ok = 0;
    for (int last = 0; last < 26; last++)
    {
        int ch = s.back() - 'a';
        if (dp[n][ch][last] or dp[n][last][ch])
            ok = 1;
    }
    
    if (!ok)
    {
        std::cout << "NO";
        return 0;
    }
    
    int i = n, last_1 = s[i - 1] - 'a', last_2;
    for (last_2 = 0; last_2 < 26; last_2++)
    {
        if (dp[n][last_1][last_2])
            break;
        if (dp[n][last_2][last_1])
        {
            std::swap(last_1, last_2);
            break;
        }
    }
    
    std::string ans;
    while (i > 0)
    {
        int cur = s[i - 1] - 'a';
        if (last_1 == cur)
            ans += '0';
        else
            ans += '1';
        
        std::tie(last_1, last_2) = par[i][last_1][last_2];
        i--;
    }
    
    std::reverse(std::begin(ans), std::end(ans));
    std::cout << "YES\n" << ans;

    return 0;
}