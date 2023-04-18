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

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    std::vector<std::pair<int, int>> b(n);
    for (int i = 0; i < n; i++)
        b[i] = {a[i], i};

    std::sort(std::begin(b), std::end(b));

    auto psq = [&](i64 x)
    {
        i64 left = 1, right = sqrtl(x) + 10;
        while (left <= right)
        {
            i64 mid = std::midpoint(left, right);
            if (mid * mid == x)
                return true;
            else if (mid * mid < x)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return false;
    };

    DSU dsu(n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (psq(1LL * i * j))
                dsu.unite(i - 1, j - 1);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i].first and !dsu.same(i, b[i].second))
        {
            std::cout << "NO\n";
            return;
        }
    }

    std::cout << "YES\n";
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