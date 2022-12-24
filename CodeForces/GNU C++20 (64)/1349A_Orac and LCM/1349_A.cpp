#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

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

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    SegmentTree<int> st(a, 0, [&](auto &x, auto &y)
    {
        return std::gcd(x, y);
    });

    i64 ans = 0;
    for (int i = 0; i < n - 1; i++)
        ans = std::gcd(ans, 1LL * (a[i] / st.get(i, n - 1)) * st.get(i + 1, n - 1));

    std::cout << ans;
    
    return 0;
}