#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

class DSU
{
    std::vector<int> rnk, par;
public:
    DSU() {}
    DSU(int n) : rnk(n, 1), par(n) { std::iota(par.begin(), par.end(), 0); }
    int get(int x)
    {
        while (x != par[x]) x = par[x] = par[par[x]];
        return x;
    }
    bool unite(int x, int y)
    {
        int p1 = get(x), p2 = get(y);
        if (p1 == p2)
            return false;
        else
        {
            if (rnk[p2] > rnk[p1])
                std::swap(p1, p2);

            par[p2] = p1, rnk[p1] += rnk[p2], rnk[p2] = 0;
            return true;
        }
    }
    bool same(int x, int y)
    {
        return get(x) == get(y);
    }
    int size(int x)
    {
        return rnk[get(x)];
    }
};

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];

    int start = 1;
    DSU dsu(n + 2);

    for (int i = 1; i <= n; i++)
    {
        int x = i, y = i + a[i];
        y = std::max(0, y);
        y = std::min(n + 1, y);
        dsu.unite(x, y);
    }

    int cnt = 1;
    i64 ans = 0;
    std::vector<int> vis(n + 1, 0);
    while (1 <= start and start <= n and !vis[start])
    {
        ans += dsu.size(0) + dsu.size(n + 1) - cnt;
        ans -= dsu.same(start, 0) + dsu.same(start, n + 1);
        print(ans)

        vis[start] = 1;
        start += a[start];
        cnt++;
    }

    if (1 + a[1] <= 0 or 1 + a[1] > n)
        ans += (n + 1LL) * n;
    else
    {
        start = 1;
        std::fill(std::begin(vis), std::end(vis), 0);
        while (1 <= start and start <= n and !vis[start])
        {
            ans += n + 1;
            vis[start] = 1;
            start += a[start];
        }
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