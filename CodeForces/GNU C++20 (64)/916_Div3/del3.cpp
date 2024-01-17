#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

std::string solve(int a, int b, int c, int d)
{
    const int N = 1e3 + 1;
    std::vector dp(N, std::vector(N, false));
    dp[a][b] = true;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (dp[i][j])
            {
                if (i + j < N)
                    dp[i][j + i] = dp[i + j][j] = true;
            }
        }
    }

    return dp[c][d] ? "YES" : "NO";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    print(solve(1, 4, 5, 9))
    
    return 0;
}