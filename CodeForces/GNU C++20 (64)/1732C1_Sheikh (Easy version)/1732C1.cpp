#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::vector<i64> prefSum(n + 1), prefXor(n + 1);
    for (int i = 1; i <= n; i++)
    {
        prefSum[i] = prefSum[i - 1] + a[i - 1];
        prefXor[i] = prefXor[i - 1] ^ a[i - 1];
    }

    i64 val = prefSum[n] - prefXor[n];

    auto pref = [&](int start, int end)
    {
        return prefSum[end] - prefSum[start - 1] - (prefXor[end] ^ prefXor[start - 1]);
    };

    auto best  = [&](int end)
    {
        int ans = end;

        int left = 1, right = end;
        while (left <= right)
        {
            int mid = std::midpoint(left, right);

            if (pref(mid, end) == val)
                ans = mid, left = mid + 1;
            else
                right = mid - 1;
        }

        return ans;
    };

    while (q--)
    {
        int l, r;
        std::cin >> l >> r;

        std::array<int, 2> ans {1, n};
        for (int i = l; i <= r; i++)
        {
            auto start = best(i);
            print(ans, start, i);
            ans = std::max(ans, {start, i}, [&](auto &x, auto &y)
            {
                if (pref(y[0], y[1]) > pref(x[0], x[1]))
                    return true;
                else if (pref(y[0], y[1]) == pref(x[0], x[1]) and y[1] - y[0] < x[1] - x[0])
                    return true;
                return false;
            });
            print(ans);
        }

        std::cout << ans[0] << " " << ans[1] << "\n";
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--)
        solve();

    return 0;
}