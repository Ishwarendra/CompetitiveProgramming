#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

template <typename T>
struct Fenwick
{
    const int n;
    std::vector<T> a;

    Fenwick() {}
    Fenwick(int n) : n(n), a(n, T()) {}
    template <class G>
    Fenwick(const std::vector<G> in) : Fenwick(std::size(in))
    {
        for (int i = 1; i <= n; i++)
        {
            a[i - 1] += in[i - 1];
            if (i + (i & -i) <= n)
                a[i - 1 + (i & -i)] += a[i - 1];
        }
    }

    void add(int x, T v)
    {
        for (int i = x + 1; i <= n; i += i & -i)
            a[i - 1] += v;
    }

    T sum(int x)
    {
        auto ans = T();
        for (int i = x + 1; i > 0; i -= i & -i)
            ans += a[i - 1];
        return ans;
    }

    T rangeSum(int l, int r)
    {
        if (l > r)
            return T(0);
        return sum(r) - sum(l - 1);
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n), pos(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        a[i]--;
        pos[a[i]] = i;
    }

    Fenwick<int> ft(n);

    std::vector<int> need(n), ans(n);
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        need[i] = ft.rangeSum(a[i] + 1, n - 1);
        if (need[i] == 1)
            ans[pos[m]]++;

        ft.add(a[i], 1);
        m = std::max(m, a[i]);
    }

    for (int i = 0; i < n; i++)
        ans[i] -= need[i] == 0;

    int max = *std::max_element(std::begin(ans), std::end(ans));
    int del = n + 1;
    for (int i = 0; i < n; i++)
    {
        if (ans[i] == max)
            del = std::min(del, a[i] + 1);

    }

    std::cout << del;

    return 0;
}