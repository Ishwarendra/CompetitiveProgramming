#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

template <class Info>
struct SegmentTree
{
    int n;
    std::vector<Info> info;
    SegmentTree() : n(0) {}
    SegmentTree(const std::vector<int> a)
    {
        n = std::size(a);
        info.assign(4 << std::__lg(n), Info());
        std::function<void(int, int, int)> build;
        build = [&](int l, int r, int id)
        {
            if (l > r)
                return;
            if (l == r)
            {
                info[id] = Info(a[l], l, r);
                return;
            }

            int m = (l + r) >> 1;
            build(l, m, id * 2 + 1);
            build(m + 1, r, id * 2 + 2);
            merge(id);
        };
        build(0, n - 1, 0);
    }
    void merge(int id)
    {
        info[id] = info[id * 2 + 1] + info[id * 2 + 2];
    }
    Info get(int id, int l, int r, int nl, int nr)
    {
        if (r < nl or l > nr)
            return Info();
        if (l >= nl and r <= nr)
            return info[id];

        int m = (l + r) >> 1;
        auto ret = get(2 * id + 1, l, m, nl, nr) + get(2 * id + 2, m + 1, r, nl, nr);
        return ret;
    }
    Info get(int l, int r)
    {
        return get(0, 0, n - 1, l, r);
    };
};

std::vector<std::vector<int>> pos;

int getFreq(int x, int l, int r)
{
    if (l > r)
        return -1;
    return std::upper_bound(std::begin(pos[x]), std::end(pos[x]), r) 
                - std::lower_bound(std::begin(pos[x]), std::end(pos[x]), l);
}

constexpr int inf = 4e5;
struct Info
{
    int x;
    int l, r;
    int freq;
    Info(int x = 0, int l = inf, int r = -inf) : x(x), l(l), r(r)
    {
        freq = getFreq(x, l, r);
    }
    void disp()
    {
        std::cout << x << ": (" << l << ", " << r << ") => " << freq << "\n";
    }
};

Info operator+(Info a, Info b)
{
    if (a.l == inf or a.r == -inf)
        return b;
    if (b.l == inf or b.r == -inf)
        return a;

    int L = std::min(a.l, b.l);
    int R = std::max(a.r, b.r);

    if (getFreq(a.x, L, R) > getFreq(b.x, L, R))
        return Info(a.x, L, R);
    return Info(b.x, L, R);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    pos.resize(n + 1);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        pos[a[i]].emplace_back(i);
    }

    SegmentTree<Info> st(a);
    // st.get(1, 3).disp();

    for (int id = 0; id < q; id++)
    {
        int l, r;
        std::cin >> l >> r;
        l--, r--;

        int freq = st.get(l, r).freq;
        int len = r - l + 1;
        int rem = len - (len - freq) * 2 - 1;
        std::cout << std::max(1, rem + 1) << "\n";
    }

    return 0;
}