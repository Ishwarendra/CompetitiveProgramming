#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

/**
 * Maximum testcases you need is:
 *     max(ceil(s / c_i)) over all i, where s is number of array of length >= i. (Pigeonhole)
 * Put numbers one by one in different testcases from big to small
 */

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;
    
    std::vector<int> f(k + 1), c(k);
    for (int i = 0; i < n; i++)
    {
        int a;
        std::cin >> a;
        f[a]++;
    }
    
    for (int i = 0; i < k; i++)
        std::cin >> c[i];
    
    for (int i = k - 1; i > 0; i--)
        f[i] += f[i + 1];
    
    int max = 0;
    for (int i = 1; i <= k; i++)
        max = std::max(max, (f[i] + c[i - 1] - 1) / c[i - 1]);
    
    std::vector<std::vector<int>> ans(max);
    for (int num = k, id = 0; num >= 0; num--)
    {
        int freq = f[num] - (num == k ? 0 : f[num + 1]);
        for (int i = 0; i < freq; i++, id++)
            ans[id % max].emplace_back(num);
    }
    
    std::cout << max << "\n";
    for (int i = 0; i < max; i++)
    {
        int sz = std::size(ans[i]);
        std::cout << sz << " ";
        for (int j = 0; j < sz; j++)
            std::cout << ans[i][j] << " \n"[j == sz - 1];
    }
    
    return 0;
}