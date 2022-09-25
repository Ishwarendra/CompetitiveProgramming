#include <bits/stdc++.h>
 
#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif
 
using i64 = long long;
 
template <typename T>
struct Fenwick 
{
    const int n;
    std::vector<T> a;
    
    Fenwick(int n) : n(n), a(n) {}
    Fenwick(const std::vector<T> inp) : Fenwick((int) inp.size())
    {
        for (int i = 0; i < n; i++)
            add(i, inp[i]);
    }
    void add(int x, T v) 
    {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }
    T sum(int x)  
    {
        T ans = 0;
        x++;
        for (int i = x; i > 0; i -= i & -i) {
            ans += a[i - 1];
        }
        return ans;
    }
    T rangeSum(int l, int r) 
    {
        if (l - 1 < 0)
            return sum(r);
        
        return sum(r) - sum(l - 1);
    }
}; 
 
void solve()
{
    int n;
    std::cin >> n;
 
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
 
    i64 ans = 0;
    std::sort(a.begin(), a.end());
 
    std::function<i64(int, int)> C = [&](int n, int r) -> i64
    {
        if (r > n or r < 0 or n <= 0)
            return 0LL;
        if (r == 0 or r == n)
            return 1LL;
 
        return 1LL * n * C(n - 1, r - 1) / r;
    };
 
    for (int i = 2; i < n; i++)
    {
        auto first = std::lower_bound(a.begin(), a.begin() + i + 1, a[i] - 2);
        ans += C(a.begin() + i - first, 2);
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