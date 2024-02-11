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
    std::map<int, int> id;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        id[a[i]] = 0;
    }

    for (int pos = 0; auto &[num, f] : id)
        f = pos++;

    for (int i = 0; i < n; i++)
        a[i] = id[a[i]];

    std::vector<i64> dp(n + 1);
    std::map<int, i64> m;

    for (int i = 0; i < n; i++)
    {
        dp[i + 1] = dp[i] + m[a[i]];
        m[a[i]] += i + 1;
    }

    std::cout << std::accumulate(std::begin(dp), std::end(dp), 0LL) << "\n";
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