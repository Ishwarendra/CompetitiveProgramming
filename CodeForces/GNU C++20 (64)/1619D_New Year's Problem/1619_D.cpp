#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int m, n;
    std::cin >> m >> n;

    std::vector a(m, std::vector(n, 0));
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++)
            std::cin >> a[i][j];
    }

    auto good = [&](int mid)
    {   
        std::vector<int> done(m), cnt(n);
        int ok = 0;
        for (int p = 0; p < n; p++)
        {
            for (int i = 0; i < m; i++)
            {
                if (a[i][p] >= mid)
                {
                    if (done[i])
                        ok = 1;

                    done[i] = 1;
                    cnt[p] = 1;
                }
            }
        }

        return ok and std::accumulate(std::begin(cnt), std::end(cnt), 0) == n;
    };

    int left = 1, right = 1e9;
    int ans = 1;

    while (left <= right)
    {
        int mid = std::midpoint(left, right);
        if (good(mid))
            ans = mid, left = mid + 1;
        else
            right = mid - 1;
    }

    std::cout << ans << "\n";
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