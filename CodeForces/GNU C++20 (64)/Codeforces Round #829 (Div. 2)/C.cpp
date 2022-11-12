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

    std::vector<std::pair<int, int>> ans;
    for (int i = 0; i < n - 1; i += 2)
    {
        if (a[i] == a[i + 1])
            ans.emplace_back(i + 1, i + 2);
        else
        {
            ans.emplace_back(i + 1, i + 1);
            ans.emplace_back(i + 2, i + 2);
        }
    }

    if (n % 2 == 0)
    {
        std::cout << std::size(ans) << "\n";
        for (int i = 0; i < std::ssize(ans); i++)
            std::cout << ans[i].first << " " << ans[i].second << "\n";
    }
    else
        std::cout << "-1\n";
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