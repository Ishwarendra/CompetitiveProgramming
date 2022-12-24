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
    std::vector<int> pos;

    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        if (a[i] == 0)
            pos.emplace_back(i);
    }

    std::vector<i64> pref(n);
    pref[0] = a[0];

    for (int i = 1; i < n; i++)
        pref[i] = pref[i - 1] + a[i];

    if (pos.empty())
        std::cout << std::count(std::begin(pref), std::end(pref), 0LL) << "\n";
    else
    {
        int ans = std::count(std::begin(pref), std::begin(pref) + pos[0], 0LL);
        pos.emplace_back(n);

        for (int i = 1; i < std::ssize(pos); i++)
        {
            std::map<i64, int> m;
            int max = 0;
            for (int j = pos[i - 1]; j < pos[i]; j++)
                max = std::max(max, ++m[pref[j]]);

            // print(max, pos[i - 1],pos[i])
            ans += max;
        }

        std::cout << ans << "\n";
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