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

    int n, k;
    std::cin >> n >> k;

    std::vector a(n, std::vector(k, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
            std::cin >> a[i][j];
    }

    std::sort(std::begin(a), std::end(a));
    auto get = [&](int i, int j)
    {
        std::vector<int> c(k);
        for (int id = 0; id < k; id++)
        {
            if (a[i][id] == a[j][id])
                c[id] = a[i][id];
            else
                c[id] = 3 - a[i][id] - a[j][id];
        }

        return c;
    };

    std::map<std::vector<int>, int> cnt;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            auto c = get(i, j);
            if (std::binary_search(std::begin(a), std::end(a), c))
                cnt[c]++;
        }
    }

    i64 ans = 0;
    for (auto &[c, f] : cnt)
        ans += f * (f - 1LL) / 2;

    std::cout << ans;

    return 0;
}