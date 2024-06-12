#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

/**
 * Tough
 * https://en.wikipedia.org/wiki/Hadamard_matrix
 */

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int k;
    std::cin >> k;
    
    std::vector ans(k + 1, std::vector(1, std::vector<int>(1, 1)));
    
    auto get = [&](auto &&self, int n) -> void
    {
        if (n == 0)    
            return;
        
        self(self, n - 1);
        ans[n] = std::vector(1 << n, std::vector(1 << n, 0));
        int sz = (1 << n);
        
        for (int i = 0; i < sz; i++)
        {
            for (int j = 0; j < sz; j++)
                ans[n][i][j] = ans[n - 1][i % (sz >> 1)][j % (sz >> 1)];
        }
        
        for (int i = (sz >> 1); i < sz; i++)
        {
            for (int j = (sz >> 1); j < sz; j++)
                ans[n][i][j] *= -1;
        }
    };
    
    get(get, k);
    for (int i = 0; i < (1 << k); i++)
    {
        for (int j = 0; j < (1 << k); j++)
            std::cout << (ans[k][i][j] == 1 ? '+' : '*');
        std::cout << "\n";
    }

    return 0;
}
