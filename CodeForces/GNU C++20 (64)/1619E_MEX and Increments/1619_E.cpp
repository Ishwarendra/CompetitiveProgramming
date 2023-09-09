#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::map<int, int> m, extra;
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        m[x]++;
    }

    for (auto &[num, f] : m)
    {
        if (f > 1)
            extra[num] = f - 1;
    }

    std::vector<i64> ans(n + 1, -1);
    ans[0] = (m.contains(0) ? m[0] : 0);

    i64 prev = 0;
    for (int mex = 0; mex <= n; mex++)
    {
        if (m.contains(mex))
            ans[mex] = prev + m[mex];
        else
        {
            ans[mex] = prev;
            auto it = extra.lower_bound(mex);
            
            if (it == std::begin(extra))
                break;

            it = std::prev(it);

            prev += std::abs(it->first - mex);
            it->second--;
            m[mex]++;
            if (it->second == 0)
                extra.erase(it);
        }
    }

    for (int i = 0; i <= n; i++)
        std::cout << ans[i] << " \n"[i == n];
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