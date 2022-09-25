#include<bits/stdc++.h>
 
#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
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
    
    const int M = 30;
 
    int n, m;
    std::cin >> n >> m;
 
    std::vector<std::tuple<int, int, int>> constraints(m);
    std::vector<std::vector<int>> nums(M, std::vector<int>(n));
    std::vector<int> ans(n);
 
    auto getBit = [&](int x, int pos)
    {
        return (x >> pos) & 1;
    };
 
    for (auto &[l, r, q] : constraints)
    {
        std::cin >> l >> r >> q;
        l--, r--;
 
        for (int i = 0; i < M; i++)
        {
            if (getBit(q, i))
            {
                nums[i][l]++;
                if (r + 1 < n)
                    nums[i][r + 1]--;
            }
        }
    }
 
    for (int i = 0; i < M; i++)
    {
        for (int j = 1; j < n; ++j)
            nums[i][j] += nums[i][j - 1];
    }
 
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < n; ++j)
            nums[i][j] = (nums[i][j] >= 1 ? 1 : 0);
    }
 
    for (int i = 0; i < n; i++)
    {
        int num = 0;
        for (int j = 0; j < M; j++)
        {
            if (nums[j][i])
                num |= (1 << j);
        }
 
        ans[i] = num;
    }
 
    SegmentTree<int> st(ans, (1 << M) - 1, [&](const int &a, const int &b)
    {
        return a & b;
    });
 
    for (auto [l, r, q] : constraints)
    {
        if (st.get(l, r) != q)
        {
            std::cout << "NO\n";
            return 0;
        }
    }
 
    std::cout << "YES\n";
    for (int i = 0; i < n; ++i)
        std::cout << ans[i] << " \n"[i == n - 1];
    
    return 0;
}