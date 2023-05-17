#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

template <class Info>
struct SegTree
{
    int n;
    std::vector<Info> info;
    SegTree() : n(0) {}

    template <typename T>
    SegTree(const std::vector<T> &a) 
    {
        n = std::size(a);
        info.assign(4 << std::__lg(n), Info());
        std::function<void(int, int, int)> build;

        build = [&](int id, int l, int r)
        {
            if (l > r)
                return;
            if (l == r)
            {
                info[id] = Info(l, a[l]);
                return;
            }
            int m = (l + r) >> 1;
            build(2 * id + 1, l, m);
            build(2 * id + 2, m + 1, r);
            merge(id);
        }; 
        build(0, 0, n - 1);
    }

    void merge(int id)
    {
        info[id] = info[id * 2 + 1] + info[id * 2 + 2];
    }
    void update(int id, int l, int r, int x, const Info &v)
    {
        if (l > r)
            return;
        if (r == l)
        {
            info[id] = v;
            return;
        }

        int m = (l + r) >> 1;
        if (x <= m)
            update(2 * id + 1, l, m, x, v);
        else 
            update(2 * id + 2, m + 1, r, x, v);
        merge(id);
    }
    void update(int id, const Info &v) 
    {
        update(0, 0, n - 1, id, v);
    }

    Info get(int id, int l, int r, int nl, int nr)
    {
        if (r < nl or l > nr)
            return Info();
        if (l >= nl and r <= nr)
            return info[id];

        int m = (l + r) >> 1;
        return get(2 * id + 1, l, m, nl, nr) + get(2 * id + 2, m + 1, r, nl, nr);
    }
    Info get(int l, int r)
    {
        return get(0, 0, n - 1, l, r);
    }
};

constexpr int inf = 1e9 + 1;
struct Min
{
    int id;
    int val;
    Min() : id(-1), val(inf) {}
    Min(int id, int val = inf) : id(id), val(val) {};
};

Min operator+(Min a, Min b)
{
    if (a.val < b.val)
        return a;
    return b;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    SegTree<Min> st(a);

    std::function<i64(int, int, i64)> f;
    f = [&](int l, int r, i64 sub)
    {
        if (l > r)
            return 0LL;

        int id = st.get(l, r).id;
        int x = std::max(0LL, a[id] - sub);
        sub += x;
        return std::min<i64>(f(l, id - 1, sub) + f(id + 1, r, sub) + x, r - l + 1LL);
    };

    std::cout << f(0, n - 1, 0);

    return 0;
}