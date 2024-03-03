#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
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
                info[id] = Info(a[l], l);
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
    std::array<int, 2> max, smax;
    Info(std::array<int, 2> max = {-1, 0}, std::array<int, 2> smax = {-1, 0}) 
        : max(max), smax(smax) {}
};

Info operator+(const Info &a, const Info &b)
{
    std::array<int, 2> max{}, smax{};
    std::set<int, std::greater<>> s { a.max[0], a.smax[0], b.max[0], b.smax[0], -1 };

    assert(std::size(s) > 1);
    max[0] = *std::begin(s);
    s.erase(std::begin(s));
    smax[0] = *std::begin(s);

    if (a.max[0] == max[0])
        max[1] += a.max[1];
    if (b.max[0] == max[0])
        max[1] += b.max[1];

    if (a.max[0] == smax[0])
        smax[1] += a.max[1];
    if (a.smax[0] == smax[0])
        smax[1] += a.smax[1];

    if (b.max[0] == smax[0])
        smax[1] += b.max[1];
    if (b.smax[0] == smax[0])
        smax[1] += b.smax[1];

    return Info(max, smax);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    SegmentTree<Info> seg(n);
    for (int i = 0; i < n; i++)
        seg.update(i, Info({a[i], 1}, {-1, 0}));

    while (q--)
    {
        int t;
        std::cin >> t;

        if (t == 1)
        {
            int id, x;
            std::cin >> id >> x;
            --id;

            a[id] = x;
            seg.update(id, Info({a[id], 1}, {-1, 0}));
        }
        else
        {
            int l, r;
            std::cin >> l >> r;
            l--, r--;

            auto [max, smax] = seg.get(l, r);
            std::cout << smax[1] << "\n";
        }
    }
    
    return 0;
}