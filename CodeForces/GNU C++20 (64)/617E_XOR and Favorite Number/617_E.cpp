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
    Query() : l(), r(), id() {}
    Query(int l, int r, int id) : l(l), r(r), id(id) {}
};

constexpr int N = 2e6 + 1;

struct DS
{
    std::array<int, N> cnt{};
    i64 ans;
    int k;

    DS(int k) : ans(0), k(k) {}

    void add(int x)
    {
        ans += cnt[x ^ k];
        cnt[x]++;
    }
    void remove(int x)
    {
        cnt[x]--;
        ans -= cnt[x ^ k];
    }
    i64 get() { return ans; }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q, k;
    std::cin >> n >> q >> k;

    std::vector<int> a(n), pref(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    pref[0] = a[0];
    for (int i = 1; i < n; i++)
        pref[i] = pref[i - 1] ^ a[i];

    const int m = std::sqrt(n);
    auto block_num = [&](int x) { return x / m; };

    auto cmp = [&](const Query &first, const Query &second)
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
    DS ds(k);
    ds.add(0);

    std::vector<i64> ans(q);

    int cur_l = 0, cur_r = -1;
    for (auto &[l, r, id] : query)
    {
        while (cur_r < r)
            ds.add(pref[++cur_r]);
        while (cur_l < l)
        {
            if (cur_l > 0)
                ds.remove(pref[cur_l - 1]);
            else
                ds.remove(0);
            cur_l++;
        }
        while (cur_r > r)
            ds.remove(pref[cur_r--]);
        while (cur_l > l)
        {
            cur_l--;
            if (cur_l > 0)
                ds.add(pref[cur_l - 1]);
            else
                ds.add(0);
        }

        ans[id] = ds.get();
    }

    for (int i = 0; i < q; i++)
        std::cout << ans[i] << "\n";
    
    return 0;
}