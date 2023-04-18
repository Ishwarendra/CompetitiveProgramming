#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr i64 inf = 1e2;

template<typename T, class F = std::function<T(const T&, const T&)>>
struct SegmentTree
{
    const int n;
    const T null_val;
    std::vector<T> tree;
    F f;

    template <typename G>
    SegmentTree(const std::vector<G> in, const T null_val, const F& f) 
        : n(int(std::size(in))), tree(2 * n, null_val), f(f), null_val(null_val)
    {
        for (int i = 0; i < n; ++i)
            tree[i + n] = in[i];

        for (int i = n - 1; i >= 0; i--)
            tree[i] = f(tree[i << 1], tree[i << 1 | 1]);
    }
    void add(int id, T x)
    {
        T val = x - get(id, id);
        update(id, val);
    }
    void update(int id, T val)
    {
        for (tree[id += n] = val; id >>= 1; )
            tree[id] = f(tree[id << 1], tree[(id << 1) | 1]);
    }
    T get(int l, int r) 
    {
        T resL = null_val, resR = null_val;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                resL = f(resL, tree[l++]);
            if (r & 1)
                resR = f(tree[--r], resR);
        }

        return f(resL, resR);
    }
};

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n + 1);
    for (int i = 0; i < n; i++) 
        std::cin >> a[i + 1];

    std::vector<int> cold(k + 1), hot(k + 1);
    for (int i = 0; i < k; i++)
        std::cin >> cold[i + 1];
    for (int i = 0; i < k; i++)
        std::cin >> hot[i + 1];

    // f(i, c, cpu1, cpu2): run program i on cpu-c such that 
    // last program run on cpu-1 is cpu1 and cpu-2 is cpu2 

    SegmentTree<i64> dp(std::vector(k + 1, inf), inf, [&](auto &x, auto &y)
        {
            return std::min(x, y);
        });
    dp.update(0, 0);

    i64 add = 0;
    for (int i = 0; i < k; i++)
        std::cout << dp.get(i, i) << " \n"[i == k - 1];

    for (int i = 1; i <= n; i++)
    {
        int cur = a[i];
        int prev = a[i - 1];

        i64 cost = (prev == cur ? hot[cur] : cold[cur]);
        add += cost;

        i64 neww = dp.get(0, k) + cold[cur] - cost;
        i64 old = dp.get(prev, prev);
        dp.update(prev, std::min(neww, old));

        neww = dp.get(cur, cur) + hot[cur] - cost;
        old = dp.get(prev, prev);
        dp.update(prev, std::min(neww, old));

        for (int i = 0; i < k; i++)
            std::cout << dp.get(i, i) << " \n"[i == k - 1];
    }

    std::cout << add + dp.get(1, k) << "\n";
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
