#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

template <typename T = int, class F = std::function<T(const T&, const T&)>>
class SparseTable
{
public:
    const int n;
    std::vector<std::vector<T>> mat;
    F func;

    SparseTable(const std::vector<T>& a, const F& f) : func(f), n(std::size(a))
    {
        int max_log = 32 - __builtin_clz(n);
        mat.resize(max_log);
        mat[0] = a;
        for (int j = 1; j < max_log; j++)
        {
            mat[j].resize(n - (1 << j) + 1);
            for (int i = 0; i <= n - (1 << j); i++)
                mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);

        }
    }

    T get(int from, int to) const
    {
        assert(0 <= from && from <= to && to <= n - 1);
        int lg = 32 - __builtin_clz(to - from + 1) - 1;
        return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
    }
};

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    if (std::size(std::set(std::begin(a), std::end(a))) == 1)
    {
        std::cout << "0\n";
        return;
    }

    int left = 1, right = n;
    int ans = 0;

    SparseTable<int> st(a, [&](int x, int y) { return std::gcd(x, y); });

    auto good = [&](int mid)
    {
        std::vector<int> b(n);
        b[n - 1] = std::gcd(a[n - 1], st.get(0, mid - 1));
        for (int i = 0; i < n - 1; i++)
        {
            b[i] = st.get(i, std::min(n - 1, i + mid));
            if (i + mid > n - 1)
            {
                int left = mid - (n - 1 - i);
                b[i] = std::gcd(b[i], st.get(0, left - 1));
            }
        }

        return std::size(std::set(std::begin(b), std::end(b))) == 1;
    };

    while (left <= right)
    {
        int mid = std::midpoint(left, right);
        if (good(mid))
            ans = mid, right = mid - 1;
        else
            left = mid + 1;
    }

    std::cout << ans << "\n";
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