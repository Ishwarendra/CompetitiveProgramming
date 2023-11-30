#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

template<class Info,
    class Merge = std::plus<Info>>
struct SegmentTree
{
    const int n;
    const Merge merge;
    std::vector<Info> info;
    SegmentTree(int n = 0) : n(n), merge(Merge()), info(4 << std::__lg(n)) {}
 
    template <typename T>
    SegmentTree(const std::vector<T> a) : SegmentTree(std::size(a))
    {
        std::function<void(int, int, int)> build;
        build = [&](int l, int r, int id)
        {
            if (l > r)
                return;
            if (l == r)
            {
                info[id] = Info(a[l]);
                return;
            }
 
            int m = (l + r) >> 1;
            build(l, m, id * 2 + 1);
            build(m + 1, r, id * 2 + 2);
            pull(id);
        }; 
        build(0, n - 1, 0);
    } 
    void pull(int id)
    {
        info[id] = merge(info[id * 2 + 1], info[id * 2 + 2]);
    }
    void update(int id, int l, int r, int x, const Info &v)
    {
        if (l > r)
            return;
        if (l == r)
        {
            info[id] = v;
            return;
        }
 
        int m = (l + r) >> 1;
        if (x <= m)
            update(2 * id + 1, l, m, x, v);
        else
            update(2 * id + 2, m + 1, r, x, v);
        pull(id);
    }
    void update(int x, const Info &v)
    {
        update(0, 0, n - 1, x, v);
    }
    Info get(int id, int l, int r, int a, int b)
    {
        if (r < a or l > b)
            return Info();
        if (l >= a and r <= b)
            return info[id];
 
        int m = (l + r) >> 1;
        return merge(get(2 * id + 1, l, m, a, b), get(2 * id + 2, m + 1, r, a, b));
    }
    Info get(int l, int r)
    {
        return get(0, 0, n - 1, l, r);
    };

    template <class F>
    int findFirst(int id, int l, int r, int a, int b, F pred)
    {
        if (r < a or l > b or !pred(info[id]))
            return -1;

        if (l == r)
            return l;

        int m = (l + r) >> 1;
        int res = findFirst(2 * id + 1, l, m, a, b, pred);
        if (res == -1)
            res = findFirst(2 * id + 2, m + 1, r, a, b, pred);

        return res;
    }

    template <class F>
    int findFirst(int l, int r, F pred) { return findFirst(0, 0, n - 1, l, r, pred); }

    template <class F>
    int findLast(int id, int l, int r, int a, int b, F pred)
    {
        if (r < a or l > b or !pred(info[id]))
            return -1;

        if (l == r)
            return l;

        int m = (l + r) >> 1;
        int res = findLast(2 * id + 2, m + 1, r, a, b, pred);
        
        if (res == -1)
            res = findLast(2 * id + 1, l, m, a, b, pred);

        return res;
    }

    template <class F>
    int findLast(int l, int r, F pred) { return findLast(0, 0, n - 1, l, r, pred); }
};

struct Info 
{
    std::vector<int> x;
    Info() {}
    Info(int x) : x(1, x) {}
    Info(const std::vector<int> x) : x(x) {}
};

Info operator+(const Info &a, const Info &b)
{
    Info c;
    std::merge(std::begin(a.x), std::end(a.x), std::begin(b.x), std::end(b.x), std::back_inserter(c.x));
    return c;
};

void solve()
{
    int n, q;
    std::cin >> n >> q;

    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++)  
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;

        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    std::vector<int> p(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> p[i];
        p[i]--;
    }

    std::vector<int> label(n), sz(n);
    int time = 0;
    auto dfs = [&](auto &&self, int u, int p) -> void
    {
        label[u] = time++;
        sz[u] = 1;
        for (auto v : adj[u])
        {
            if (v == p)
                continue;
            self(self, v, u);
            sz[u] += sz[v];
        }
    }; dfs(dfs, 0, 0);

    std::vector<int> _(n);
    for (int i = 0; i < n; i++)
        _[i] = label[p[i]];
    p = std::move(_);

    SegmentTree<Info> st(p);

    while (q--)
    {
        int l, r, x;
        std::cin >> l >> r >> x;
        l--, r--, x--;

        int L = label[x], R = label[x] + sz[x] - 1;
        auto f = [&](const Info &a)
        {
            auto it = std::lower_bound(std::begin(a.x), std::end(a.x), L);
            if (it == std::end(a.x))
                return false;

            return *it <= R;
        };

        int start = st.findFirst(l, r, f);

        std::cout << (start == -1 ? "NO\n" : "YES\n");
    }

    std::cout << "\n";
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