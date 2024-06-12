#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

/**
 * log2(1e6) <= 20
 * {1, 2, 4, 2} => upto 7 + 2 = 9
 * if k = 10
 * prefix = {1, 2, 4, 2}
 * For suffix you need to just make sure if you add `x` then `x + k` can be made as well
 */

constexpr i64 inf = 1e9;

void solve()
{
    int n, k;
    std::cin >> n >> k;
    
    i64 sum = 0;
    std::vector<i64> ans;
    while (sum < k - 1)
    {
        ans.emplace_back(std::min(k - 1 - sum, sum + 1));
        sum += ans.back();
    }
    
    ans.emplace_back(k + 1);
    ans.emplace_back(k + 1);
    ans.emplace_back(2 * k + 1);

    i64 num = k + 1 + k + 2;
    while (sum <= n)
    {
        ans.emplace_back(std::min(num, inf));
        sum += ans.back();
        num = sum + 1;
    }

    std::sort(std::begin(ans), std::end(ans));
    int sz = std::size(ans);
    assert(sz <= 25);
    
    std::cout << sz << "\n";
    for (int i = 0; i < sz; i++)
        std::cout << ans[i] << " \n"[i == sz - 1];
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    
    // print(std::__lg(int(1e6)));
    
    while (t--)
        solve();
    
    return 0;
}