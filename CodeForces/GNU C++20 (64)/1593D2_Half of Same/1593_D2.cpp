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
    std::map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        m[a[i]]++;
    }

    std::sort(std::begin(a), std::end(a));
    std::set<int> diff;
    for (int i = 0; i < std::size(a); i++)
    {
        for (int j = 0; j < std::size(a); j++)
        {
            if (a[j] - a[i] == 0)
                continue;
            diff.emplace(std::abs(a[j] - a[i]));
        }
    }

    auto divisor = [&](int x)
    {
        std::set<int> d;
        for (int i = 1; i * i <= x; i++)
        {
            if (x % i == 0)
                d.emplace(i), d.emplace(x / i);
        }
        
        return d;
    };

    std::set<int> options;
    for (auto x : diff)
    {
        for (auto y : divisor(x))
            options.emplace(y);
    }

    for (auto &[num, f] : m)
    {
        if (f >= n / 2)
        {
            std::cout << "-1\n";
            return;
        }
    }

    int ans = 1;

    auto f = [&](const int k)
    {
        for (int i = n / 2 - 1; i < n; i++)
        {
            int count = 1;
            for (int j = i - 1; j >= 0; j--)
            {
                // a[j] + x * k == a[i]
                if ((a[i] - a[j]) % k == 0)
                    count++;
            }

            if (count >= n / 2)
                return true;
        }

        return false;
    };

    for (int k : options)
    {
        if (f(k))
            ans = k;
    }

    std::cout << ans << "\n";
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