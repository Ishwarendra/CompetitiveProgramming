#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr i64 inf = 1e18;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector a(n, 0);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    auto factor = [&](int x)
    {
        std::vector<int> ans;
        for (int i = 1; 1LL * i * i <= x; i++)
        {
            if (x % i == 0)
            {
                if (i != 1)
                    ans.emplace_back(i);
                if (x != i * i)
                    ans.emplace_back(x / i);
            }
        }

        return ans;
    };
        
    int sum = std::accumulate(std::begin(a), std::end(a), 0);
    if (sum == 1)
    {
        std::cout << "-1\n";
        return 0;
    }

    i64 ans = inf;
    std::vector<int> pos;
    for (int i = 0; i < n; i++)
    {
        if (a[i])
            pos.emplace_back(i);
    }

    for (const auto x : factor(sum))
    {
        int cnt = 0;
        i64 cur_ans = 0, mid = x / 2;
        
        for (int i = 0; i < sum; i++)
        {
            if (cnt < x)
                cur_ans += std::abs(pos[i] - pos[mid]);
            if (cnt == x - 1)
                cnt = -1, mid += x;

            cnt++;
        }
        
        ans = std::min(ans, cur_ans);
    }

    std::cout << ans << "\n";

    return 0;
}