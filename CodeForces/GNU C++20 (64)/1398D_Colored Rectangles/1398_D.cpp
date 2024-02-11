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
    
    int r, g, b;
    std::cin >> r >> g >> b;

    std::vector<int> R(r), G(g), B(b);
    auto read = [&](std::vector<int> &a)
    {
        for (auto &x : a)
            std::cin >> x;
        std::sort(std::rbegin(a), std::rend(a));
    };

    read(R); read(G); read(B);
    std::vector dp(r + 1, std::vector(g + 1, std::vector<int>(b + 1, -inf)));
    dp[0][0][0] = 0;

    auto chmax = [&](int &x, int y)
    {
        if (x < y)
            x = y;
    };

    auto f = [&](auto &&self, int i, int j, int k) -> int
    {
        if (i < 0 or j < 0 or k < 0)
            return 0;
        int &ans = dp[i][j][k];
        if (ans != -inf)
            return ans;

        ans = 0;

        if (i - 1 >= 0 and j - 1 >= 0)
            chmax(ans, self(self, i - 1, j - 1, k) + R[i - 1] * G[j - 1]);
        if (i - 1 >= 0 and k - 1 >= 0)
            chmax(ans, self(self, i - 1, j, k - 1) + R[i - 1] * B[k - 1]);
        if (j - 1 >= 0 and k - 1 >= 0)
            chmax(ans, self(self, i, j - 1, k - 1) + G[j - 1] * B[k - 1]);

        chmax(ans, self(self, i - 1, j, k));
        chmax(ans, self(self, i, j - 1, k));
        chmax(ans, self(self, i, j, k - 1));

        return ans;
    };
    
    std::cout << f(f, r, g, b);

    return 0;
}