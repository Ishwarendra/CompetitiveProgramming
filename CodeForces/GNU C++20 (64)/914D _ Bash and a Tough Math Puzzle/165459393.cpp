#include <bits/stdc++.h>
 
#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(...) 1;
#define print(...) 1;
#endif
 
struct SegmentTree
{
    const int n;
    std::vector<int> tree;
    int done;
 
    SegmentTree(int _n) : n(_n), tree(4 * _n + 1) {}
    SegmentTree(const std::vector<int> &in) : SegmentTree((int)(std::size(in)))
    {
        std::function<void(int, int, int)> build;
        build = [&](int p, int l, int r)
        {
            if (l == r)
            {
                tree[p] = in[l - 1];
                return;
            }
 
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m + 1, r);
 
            tree[p] = std::gcd(tree[p << 1], tree[(p << 1) | 1]);
        };
 
        build(1, 1, n);
    }
 
    void update(int id, int p, int v, int l, int r)
    {
        if (r == l)
        {
            tree[p] = v;
            return;
        }
 
        int m = (l + r) / 2;
 
        if (id <= m)
            update(id, p << 1, v, l, m);
        else
            update(id, (p << 1) | 1, v, m + 1, r);
 
        tree[p] = std::gcd(tree[p << 1], tree[(p << 1) | 1]);
    }
 
    void update(int i, int v)
    {
        update(i, 1, v, 1, n);
    }
 
    // maybe prune by not checking after sum 2
    int query(int p, int ns, int ne, int qs, int qe, int x)
    {
        if (done)
            return 2;
        
        // no overlap
        if (ns > qe or ne < qs)
            return 0;
 
        // complete overlap
        if (qs <= ns and qe >= ne)
        {
            if (tree[p] % x == 0)
                return 0;
            if (ns == ne) // can't go further down
                return 1;
        }
 
        int nm = (ns + ne) / 2;
        int left = 0, right = 0;
 
        if (tree[p << 1] % x)
        {
            left = query(p << 1, ns, nm, qs, qe, x);
            if (left > 2)
                done = 1;
        }
        if (tree[(p << 1) | 1] % x)
        {
            right = query((p << 1) | 1, nm + 1, ne, qs, qe, x);
            if (right > 2)
                done = 1;
        }
 
        if (left + right > 2)
            done = 1;
        return left + right;
    }
 
    int get(int l, int r, int x)
    {
        done = 0;
        int count = query(1, 1, n, l, r, x);
        print(count, l, r, x);
        return count <= 1;
    }
};
 
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int n;
    std::cin >> n;
 
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
 
    int q;
    std::cin >> q;
 
    SegmentTree st(a);
 
    while (q--)
    {
        int t;
        std::cin >> t;
 
        if (t == 1)
        {
            int l, r, x;
            std::cin >> l >> r >> x;
 
            if (st.get(l, r, x))
                std::cout << "YES\n";
            else
                std::cout << "NO\n";
        }
        else
        {
            int i, v;
            std::cin >> i >> v;
 
            st.update(i, v);
        }
    }
 
    return 0;
}