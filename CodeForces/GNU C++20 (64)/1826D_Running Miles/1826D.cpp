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

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    auto sum = [&](int l, int r)
    {
        assert(r - l == 2);
        int res = 0;
        for (int i = l; i <= r; i++)
            res += a[i];
        return res;
    };

    auto erase = [&](auto &m, auto x)
    {
        m.erase(m.find(x));
    };

    std::function<int(int, int)> f = [&](int l, int r)
    {
        if (r - l + 1 < 3)
            return 0;

        if (r - l + 1 == 3)
            return sum(l, r) - 2;

        int m = (l + r) >> 1;
        int ans = std::max(f(l, m), f(m + 1, r));

        std::multiset<int, std::greater<>> left, right;
        for (int i = m, d = 1; i >= l; i--, d++)
            left.emplace(a[i] - d);
        for (int i = m + 1, d = 0; i <= r; i++, d++)
            right.emplace(a[i] - d);
        
        auto get = [&]()
        {
            if (left.empty() or right.empty())
                return 0;

            int res = *std::begin(left) + *std::begin(right);
            return res;
        };

        for (int i = m, d = 1; i >= l; i--, d++)
        {
            erase(left, a[i] - d);
            ans = std::max(ans, get() + a[i]);
        }

        for (int i = m, d = 1; i >= l; i--, d++)
            left.emplace(a[i] - d);

        for (int i = m + 1, d = 0; i <= r; i++, d++)
        {
            erase(right, a[i] - d);
            ans = std::max(ans, get() + a[i]);
        }

        return ans;
    };

    std::cout << f(0, n - 1) << "\n";
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