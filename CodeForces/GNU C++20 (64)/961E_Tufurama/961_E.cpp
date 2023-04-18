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
    
    Fenwick(int n) : n(n), a(n, T()) {}
    template <class G>
    Fenwick(const std::vector<G> in) : Fenwick(std::ssize(in))
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
        if (r < l) 
            return T(0); 
        return sum(r) - sum(l - 1); 
    }
    
    int kth(T k) 
    {
        int x = 0;
        for (int i = 1 << std::__lg(n); i; i /= 2) 
        {
            if (x + i <= n && k >= a[x + i - 1]) 
                x += i, k -= a[x - 1];
        }
        return x;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<int> a(n), pos[n];
    Fenwick<int> ft(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        a[i] = std::min(a[i] - 1, n - 1);
        ft.add(i, 1);
        pos[a[i]].emplace_back(i);
    }

    i64 ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += ft.rangeSum(i + 1, a[i]);
        for (auto del : pos[i])
            ft.add(del, -1);
    }

    std::cout << ans;
    
    return 0;
}