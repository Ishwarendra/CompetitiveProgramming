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

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::vector<int> positive;
    for (int i = 0; i < n; i++)  
    {
        std::cin >> a[i];
        if (a[i] > 0)
            positive.emplace_back(i);
    }

    SegmentTree<int> max(a, -1e9, [](const auto x, const auto y)
    {
        return std::max(x, y);
    });

    SegmentTree<i64> sum(a, 0, [](auto x, auto y)
    {
        return x + y;
    });


    auto next_greater = [&]()
    {
        std::vector<int> ng(n);
        std::stack<int> stack;

        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] < 0)
                continue;

            while (!stack.empty() and a[i] > a[stack.top()])
                stack.pop();

            if (stack.empty())
                ng[i] = i;
            else
                ng[i] = stack.top();

            stack.push(i);            
        }

        return ng;
    };

    auto previous_greater = [&]()
    {
        std::vector<int> pg(n);
        std::stack<int> stack;

        for (int i = 0; i < n; i++)
        {
            while (!stack.empty() and a[stack.top()] < a[i])
                stack.pop();

            if (stack.empty())
                pg[i] = i;
            else
                pg[i] = stack.top();
            
            stack.push(i);
        }

        return pg;
    };

    auto ng = next_greater();
    auto pg = previous_greater();
    
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
            continue;
        
        if (max.get(pg[i], ng[i]) < sum.get(pg[i], ng[i]))
        {
            std::cout << "NO\n";
            return;
        }
    }

    for (int i = 1; i < std::ssize(positive); i++)
    {
        int prev = positive[i - 1];
        int cur = positive[i];
        if (max.get(prev, cur) < sum.get(prev, cur))
        {
            std::cout << "NO\n";
            return;
        }
    }

    std::cout << "YES\n";
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