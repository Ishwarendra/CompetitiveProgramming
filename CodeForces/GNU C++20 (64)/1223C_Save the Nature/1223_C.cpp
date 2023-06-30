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

    std::vector<int> p(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> p[i];
        p[i] /= 100;
    }

    int x, a, y, b;
    std::cin >> x >> a >> y >> b;

    i64 k;
    std::cin >> k;

    std::vector<int> contri(n);
    for (int i = a - 1; i < n; i += a)
        contri[i] += x;
    for (int i = b - 1; i < n; i += b)
        contri[i] += y;

    std::sort(std::begin(p), std::end(p), std::greater());
    
    auto good = [&](int mid)
    {
        std::vector<int> ord(mid);
        std::iota(std::begin(ord), std::end(ord), 0);
        std::sort(std::begin(ord), std::end(ord), [&](int i, int j)
        {
            return contri[i] > contri[j];
        });

        i64 ans = 0;
        for (int pos = 0; int i : ord)
            ans += contri[i] * p[pos++];
        
        return ans >= k;
    };

    int left = 1, right = n;
    int ans = -1;

    while (left <= right)
    {
        int mid = std::midpoint(left, right);
        if (good(mid))
            ans = mid, right = mid - 1;
        else
            left = mid + 1;
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