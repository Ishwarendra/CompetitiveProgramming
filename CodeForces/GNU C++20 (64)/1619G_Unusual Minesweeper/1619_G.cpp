#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

struct DSU
{
    std::vector<int> rnk, par, tim;

    DSU() {}
    DSU(int n) : rnk(n, 1), par(n), tim(n) { std::iota(par.begin(), par.end(), 0); }
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
            tim[p1] = std::min(tim[p1], tim[p2]);
            return true;
        }
    }
    bool same(int x, int y) { return get(x) == get(y); }
    int size(int x) { return rnk[get(x)]; }
    int getTime(int x) { return tim[get(x)]; }
};

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector a(n, std::array<int, 4>());
    DSU dsu(n);
    std::map<int, std::vector<std::pair<int, int>>> posx, posy;

    for (int pos = 0; auto &[x, y, t, id] : a)
    {
        std::cin >> x >> y >> t;
        id = pos++;
        dsu.tim[id] = t;
        posx[y].emplace_back(x, id);
        posy[x].emplace_back(y, id);
    }

    auto add = [&](auto &m)
    {
        for (auto &[c, p] : m)
        {
            std::sort(std::begin(p), std::end(p));
            for (int i = 1; i < std::size(p); i++)
            {
                if (p[i].first - p[i - 1].first <= k)
                    dsu.unite(p[i].second, p[i - 1].second);
            }
        }
    };

    add(posx);
    add(posy);

    std::vector<int> done(n);
    std::vector<int> tim;
    for (int i = 0; i < n; i++)
    {
        if (done[dsu.get(i)])
            continue;

        done[dsu.get(i)] = 1;
        tim.emplace_back(dsu.getTime(i));
    }
    
    std::sort(std::begin(tim), std::end(tim), std::greater());

    int left = 0, right = std::ssize(tim) - 1;
    int ans = right;

    while (left <= right)
    {
        int mid = std::midpoint(left, right);
        
        if (mid + 1 >= std::ssize(tim) or tim[mid + 1] <= mid)
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