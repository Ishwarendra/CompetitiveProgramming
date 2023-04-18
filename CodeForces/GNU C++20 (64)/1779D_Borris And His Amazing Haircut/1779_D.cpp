#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;
 
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

    std::vector<int> a(n), b(n);
    std::map<int, std::vector<int>, std::greater<>> pos;

    for (int i = 0; i < n; i++)  
        std::cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        std::cin >> b[i];
        if (b[i] != a[i])
            pos[b[i]].emplace_back(i);
    }

    int m;
    std::cin >> m;

    std::vector<int> x(m);
    std::map<int, int> freq;
    for (int i = 0; i < m; i++)
    {
        std::cin >> x[i];
        freq[x[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] < b[i])
        {
            std::cout << "NO\n";
            return;
        }
    }

    SparseTable<int> max(b, [&](auto x, auto y) { return std::max(x, y); });

    for (auto &[make, p] : pos)
    {
        int sz = std::size(p);
        int need = 0;
        for (int i = 0; i < sz;)
        {
            int j = i + 1;
            while (j < sz and max.get(p[i], p[j]) <= make)
                j++;
 
            need++;
            i = j;
        }

        if (need > freq[make])
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