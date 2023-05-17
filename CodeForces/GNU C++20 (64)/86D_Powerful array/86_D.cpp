#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

struct Query
{
    int l, r, id;

    Query() {}
    Query(int l, int r, int id) : l(l), r(r), id(id) {}
};

constexpr int N = 1e6 + 1;
struct DS 
{
    std::array<int, N> m{};
    i64 ans;
    DS() : ans(0) {}

    void add(int x)
    {
        ans -= 1LL * m[x] * m[x] * x;
        m[x]++;
        ans += 1LL * m[x] * m[x] * x;
    }
    void remove(int x)
    {
        ans -= 1LL * m[x] * m[x] * x;
        m[x]--;
        ans += 1LL * m[x] * m[x] * x;
    }
    i64 get() { return ans; }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)    
        std::cin >> a[i];

    const int m = std::sqrt(n);
    auto block_num = [&](int x)
    {
        return x / m;
    };

    auto cmp = [&](const Query& first, const Query& second)
    {
        if (block_num(first.l) == block_num(second.l))
            return first.r < second.r;
        return block_num(first.l) < block_num(second.l);
    };

    std::vector<Query> query(q);
    for (int i = 0; i < q; i++)
    {
        int l, r;
        std::cin >> l >> r;
        l--, r--;
        query[i] = Query(l, r, i);
    }

    std::sort(std::begin(query), std::end(query), cmp);
    DS ds;

    std::vector<i64> ans(q);
    int cur_l = 0, cur_r = 0;
    ds.add(a[0]);
    for (auto &[l, r, id] : query)
    {
        while (cur_r < r)
            ds.add(a[++cur_r]);
        while (cur_l < l)
            ds.remove(a[cur_l++]);
        while (cur_l > l)
            ds.add(a[--cur_l]);
        while (cur_r > r)
            ds.remove(a[cur_r--]);

        ans[id] = ds.get();
    }

    for (int i = 0; i < q; i++)
        std::cout << ans[i] << "\n";
    
    return 0;
}