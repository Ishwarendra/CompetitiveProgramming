#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    std::string s;
    std::cin >> s;

    int n = std::size(s);

    // 0 -> Bob 1 -> Alice and -1 => Draw
    std::vector dp(n + 1, std::vector(n + 1, -1));
    for (int i = 0; i < n - 1; i++)
        dp[i + 1][i + 2] = (s[i] == s[i + 1] ? -1 : 1);

    // dp[i][j] = winner for s[i...j]
    for (int len = 4; len <= n; len += 2)
    {
        for (int i = 1; i + len - 1 <= n; i++)
        {
            int j = i + len - 1;

            // option-1 alice choose s[i]
            int bob = -1; // (lose, draw, win)
            {
                // Bob tries his best to win but can he?
                std::array<int, 2> op { dp[i + 1][j - 1], dp[i + 2][j] };

                if ((op[0] == 0) or (op[1] == 0))
                    bob = 1;
                else if (op[0] == 1 and op[1] == 1)
                    bob = 0;
                else if (op[0] == -1 or op[1] == -1)
                {
                    if (op[0] == -1)
                    {
                        if (s[i - 1] > s[j - 1])
                            bob = 1;
                        else if (s[i - 1] < s[j - 1])
                            bob = 0;
                        else
                            bob = -1;
                    }
                    if (op[1] == -1)
                    {
                        if (s[i - 1] > s[i])
                            bob = 1;
                        else if (s[i - 1] < s[i])
                            bob = 0;
                        else
                            bob = -1;
                    }
                }
            }

            int bob_2 = -1;
            if (bob == 1 or bob == -1)
            {
                // alice wants to win so she tries option-2
                std::array<int, 2> op { dp[i + 1][j - 1], dp[i][j - 2] };

                if ((op[0] == 0) or (op[1] == 0))
                    bob_2 = 1;
                else if (op[0] == 1 and op[1] == 1)
                    bob_2 = 0;
                else if (op[0] == -1 or op[1] == -1)
                {
                    if (op[0] == -1)
                    {
                        if (s[j - 1] > s[i - 1])
                            bob_2 = 1;
                        else if (s[j - 1] < s[i - 1])
                            bob_2 = 0;
                        else
                            bob_2 = -1;
                    }
                    if (op[1] == -1) 
                    {
                        if (s[j - 1] > s[j - 2])
                            bob_2 = 1;
                        else if (s[j - 1] < s[j - 2])
                            bob_2 = 0;
                        else
                            bob_2 = -1;
                    }
                }
            }

            if (bob_2 == 1 and bob == 1)
                dp[i][j] = 0;
            else if (bob_2 == 0 or bob == 0)
                dp[i][j] = 1;
            else
                dp[i][j] = -1;
        }
    }

    if (dp[1][n] == 1)
        std::cout << "Alice\n";
    else if (dp[1][n] == 0)
        std::cout << "Bob\n";
    else
        std::cout << "Draw\n";

    // for (auto p : dp)
    //     print(p)
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