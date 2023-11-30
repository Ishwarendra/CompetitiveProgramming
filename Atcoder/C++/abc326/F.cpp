#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, x, y;
    std::cin >> n >> x >> y;

    std::vector<int> left, right;
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        (i % 2 ? right : left).emplace_back(x);
    }

    auto getBit = [&](int x, int pos) { return x >> pos & 1; };

    auto get = [&](std::vector<int> &a, int need) -> std::string
    {
        int n = std::size(a);
        std::vector<std::pair<int, std::string>> lsum, rsum;

        for (int mask = 0; mask < (1 << (n / 2)); mask++)
        {
            std::pair<int, std::string> val{};
            for (int i = 0; i < n / 2; i++)
            {
                val.first += (getBit(mask, i) ? 1 : -1) * a[i];
                val.second += (getBit(mask, i) ? '+' : '-');
            }

            lsum.emplace_back(val);
        }

        int rem = n - n / 2;
        for (int mask = 0; mask < (1 << rem); mask++)
        {
            std::pair<int, std::string> val{};
            for (int i = 0; i < rem; i++)
            {
                val.first += (getBit(mask, i) ? 1 : -1) * a[i + n / 2];
                val.second += (getBit(mask, i) ? '+' : '-');
            }

            rsum.emplace_back(val);
        }

        std::sort(std::begin(rsum), std::end(rsum));
        for (auto [sum, how] : lsum)
        {
            auto it = std::lower_bound(std::begin(rsum), std::end(rsum), need - sum,
                                       [&](const std::pair<int, std::string> &x, const int &y)
            {
                return x.first < y;
            });

            if (it != std::end(rsum) and it->first + sum == need)
                return how + it->second;
        }

        return "-1";
    };

    auto l = get(left, y);
    auto r = get(right, x);

    if (l == "-1" or r == "-1")
    {
        std::cout << "No";
        return 0;
    }

    char prev = '+';
    std::string ans = "Yes\n";
    for (int i = 0; i < std::size(l); i++)
    {
        if (prev == '+')
            ans += l[i] == '+' ? 'L' : 'R';
        else
            ans += l[i] == '+' ? 'R' : 'L';

        prev = l[i];

        if (i < std::size(r))
        {
            if (prev == '+')
                ans += r[i] == '+' ? 'R' : 'L';
            else
                ans += r[i] == '+' ? 'L' : 'R';

            prev = r[i];
        }
    }

    std::cout << ans;

    return 0;
}