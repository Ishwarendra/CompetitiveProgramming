#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;
using i128 = __int128;

constexpr i64 inf = 1e18;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    int k;
    std::cin >> k;

    std::vector<i64> ans(1, 1);
    int sz = 1;
    for (int phase = 0; phase < k; phase++)
    {
        i64 min = inf;
        int ans_sz = std::ssize(ans);
        int nsz = 0;
        for (int j = ans_sz - sz; j < ans_sz; j++)
        {
            i64 x = ans[j];
            for (int i = 0; i < n; i++)
            {
                if (i128(a[i]) * x > inf)
                    continue;
                
                ans.emplace_back(a[i] * x);
                min = std::min(min, ans.back());
                nsz++;
            }
        }

        if (min * i128(a[0]) > inf)
            break;

        sz = nsz;
    }

    std::sort(std::begin(ans), std::end(ans));
    ans.erase(std::unique(std::begin(ans), std::end(ans)), std::end(ans));
    std::cout << ans[k - 1];
    
    return 0;
}