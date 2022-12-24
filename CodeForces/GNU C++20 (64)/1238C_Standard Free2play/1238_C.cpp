#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int h, n;
    std::cin >> h >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    int ans = 0;
    int cur = a[0];
    for (int i = 0; i + 1 < n and cur > 2;)
    {
        print(cur, a[i+1], a[i+2], ans)
        if (i + 2 < n and cur - a[i + 1] == 1 and cur - a[i + 2] == 2)
            i += 2, cur -= 2;
        else if (cur - a[i + 1] == 1)
        {
            i++, cur -= 2;
            ans++;
        }
        else
        {
            // 10 5 4
            // 10 -> 6 -> 4
            cur = a[i + 1] + 1;
        }
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