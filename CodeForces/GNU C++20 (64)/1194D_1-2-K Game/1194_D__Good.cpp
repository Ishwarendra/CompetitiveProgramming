#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> dp(n + 1, -1);
    dp[0] = 0;
    std::function<int(int)> f = [&](int x) -> int
    {
        if (x < 0)
            return 1;
        if (dp[x] != -1)
            return dp[x];

        return dp[x] = !f(x - 1) | !f(x - 2) | !f(x - k);
    };

    std::cout << (f(n) ? "Alice\n" : "Bob\n");
    for (int a = 1; a <= n; a++)
    {
        if (!f(a))
        {
            std::cout << "Lose ";
            print(a, (a - k) / 3)
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}