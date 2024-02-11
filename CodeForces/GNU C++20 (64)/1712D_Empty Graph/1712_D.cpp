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
    int n;
    std::vector<T> a;
    
    Fenwick(int n_ = 0) { init(n_); }
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
    
    void init(int n_) 
    {
        n = n_;
        a.assign(n, T{});
    }


    void add(int x, T v) 
    {
        for (int i = x + 1; i <= n; i += i & -i) 
            a[i - 1] = a[i - 1] + v;
    }
    
    T sum(int x) 
    {
        T ans{};
        for (int i = x + 1; i > 0; i -= i & -i) 
            ans = ans + a[i - 1];
        return ans;
    }
    
    T rangeSum(int l, int r) 
    { 
        if (l > r)
            return T(0);
        return sum(r) - sum(l - 1); 
    }
};

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    std::map<int, int> id;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        id[a[i]] = 0;
    }

    id[-1] = 0;
    for (int i = 0; auto &[num, f] : id)
        f = i++;

    Fenwick<int> ft(n + 1);
    for (int i = 0; i < n; i++)
        ft.add(id[a[i]], 1);

    auto good = [&](int mid)
    {
        auto it = std::prev(id.upper_bound((mid + 1) / 2 - 1));
        int cur = it->second;
        int need = ft.sum(cur);

        auto between = [&](int x, int l, int r)
        {
            if (l > r)
                return false;
            return l <= x and x <= r;
        };

        for (int i = 0; i < n - 1; i++)
        {
            int add = between(a[i], (mid + 1) / 2, mid - 1);
            add += between(a[i + 1], (mid + 1) / 2, mid - 1);

            if (need + add <= k)
                return true;
        }

        return false;
    };

    int left = 1, right = 1e9;
    int ans = 1;

    while (left <= right)
    {
        int mid = std::midpoint(left, right);
        if (good(mid))
            ans = mid, left = mid + 1;
        else
            right = mid - 1;
    }

    std::cout << ans << "\n";
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