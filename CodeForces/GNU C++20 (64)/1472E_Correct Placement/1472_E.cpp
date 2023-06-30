#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;

struct Info
{
    int h, w;
    int id;
    Info(int h = inf, int w = inf, int id = inf) : h(h), w(w), id(id) {}
};

bool operator<(Info info1, Info info2)
{
    return std::make_pair(info1.h, info2.w) < std::make_pair(info2.h, info2.w);
}

Info min(Info a, Info b)
{
    if (a.w < b.w)
        return a;
    return b;
}

template <typename T = int, class F = std::function<T(const T&, const T&)>>
class SparseTable
{
public:
    F func;
    const int n;
    std::vector<std::vector<T>> mat;

    SparseTable(const std::vector<T>& a, const F& f) : func(f), n(std::size(a))
    {
        int max_log = 32 - __builtin_clz(n);
        mat.resize(max_log);
        mat[0] = a;
        for (int j = 1; j < max_log; j++)
        {
            mat[j].resize(n - (1 << j) + 1);
            for (int i = 0; i <= n - (1 << j); i++)
                mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
        }
    }

    T get(int from, int to) const
    {
        assert(0 <= from && from <= to && to <= n - 1);
        int lg = 32 - __builtin_clz(to - from + 1) - 1;
        return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
    }
};

void solve()
{
    int n;
    std::cin >> n;

    std::vector<Info> a(n), b(n);
    std::map<int, int> posa;
    for (int i = 0; i < n; i++)
    {
        int h, w;
        std::cin >> h >> w;
        a[i] = Info(h, w, i);
        b[i] = Info(w, h, i);
    }

    std::sort(std::begin(a), std::end(a));
    std::sort(std::begin(b), std::end(b));

    SparseTable<Info> sta(a, min), stb(b, min);

    for (int i = 0; i < n; i++)
        posa[a[i].id] = i;

    std::vector ans(n, -1);
    for (int i = 0; i < n; i++)
    {
        int j = std::upper_bound(std::begin(b), std::end(b), Info(b[i].h - 1, inf, inf)) - std::begin(b) - 1;
        if (j >= 0)
        {
            auto [h_, w_, id_] = stb.get(0, j);
            if (h_ < b[i].h and w_ < b[i].w)
                ans[b[i].id] = id_ + 1;
        }

        if (ans[b[i].id] != -1)
            continue;

        j = std::upper_bound(std::begin(a), std::end(a), Info(b[i].h - 1, inf, inf)) - std::begin(a) - 1;
        if (j >= 0)
        {
            auto [h_, w_, id_] = sta.get(0, j);
            if (h_ < b[i].h and w_ < b[i].w)
                ans[b[i].id] = id_ + 1;
        }
    }

    for (int i = 0; i < n; i++)
        std::cout << ans[i] << " \n"[i == n - 1];
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