#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

i64 gcd(i64 a, i64 b, i64& x, i64& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    i64 x1, y1;
    i64 d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(i64 a, i64 b, i64 c, i64 &x0, i64 &y0, int &g) {
    g = gcd(std::abs(a), std::abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

void shift_solution(i64 & x, i64 & y, i64 a, i64 b, i64 cnt) {
    x += cnt * b;
    y -= cnt * a;
}

void solve()
{
    int w, n, d;
    std::cin >> w >> n >> d;

    std::vector<int> a(w);
    for (int i = 0; i < w; i++)
    {
        std::cin >> a[i];
        a[i]--;
    }

    auto palin = [&]()
    {
        int i = 0, j = w - 1;
        while (i < j)
        {
            if (a[i++] != a[j--])
                return false;
        }

        return true;
    };

    if (palin())
    {
        std::cout << "0\n";
        return;
    }

    int i = 0, j = w - 1;

    int ans = 0;
    while (i < j)
    {
        int g = std::gcd(n, d);
        const int MOD = n / g;

        i64 k1, k2;
        i64 can = find_any_solution(d, n, std::abs(a[i] - a[j]), k1, k2, g);

        if (!can)
        {
            std::cout << "IMPOSSIBLE\n";
            return;
        }

        int p = d / g;
        int q = n / g;

        i64 best = std::abs(k1);
        if (k1 < 0)
        {
            shift_solution(k1, k2, p, q, -k1 / q);
            k1 = std::abs(k1);
            best = std::min({best, k1, MOD - k1});
            if (std::abs(k1) > std::abs(k1 + q))
            {
                k1 = std::abs(k1 + q);
                best = std::min({best, k1, MOD - k1});
            }
        }
        else
        {
            shift_solution(k1, k2, p, q, -k1 / q);
            k1 = std::abs(k1);
            best = std::min({best, k1, MOD - k1});
            if (std::abs(k1) > std::abs(k1 - q))
            {
                k1 = std::abs(k1 - q);
                best = std::min({best, k1, MOD - k1});
            }
        }

        ans += std::min(k1, best);
        i++, j--;
    }

    std::cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    for (int i = 1; i <= t; i++)
    {
        std::cout << "Case #" << i << ": ";
        solve();
    }
    
    return 0;
}