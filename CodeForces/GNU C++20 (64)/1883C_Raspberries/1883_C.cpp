#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    int ans = k;
    for (int i = 0; i < n; i++)
        ans = std::min(ans, ((k - a[i]) % k + k) % k);

    if (k == 4)
    {
        int cur = 2;
        for (int i = 0; i < n and cur; i++)
            cur -= a[i] % 2 == 0;

        ans = std::min(ans, cur);
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