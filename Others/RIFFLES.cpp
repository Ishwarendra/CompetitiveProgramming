#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

std::vector<int> multiply(const std::vector<int> &a, const std::vector<int> &b)
{
    int n = std::size(a);
    std::vector<int> c(n);

    for (int i = 0; i < n; i++)
        c[i] = a[b[i]];
    return c;
}

std::vector<int> power(std::vector<int> a, int b)
{
    auto ans = a;
    while (b)
    {
        if (b % 2)
            ans = multiply(ans, a);
        a = multiply(a, a);
        b >>= 1;
    }

    return ans;
}

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n / 2; i++)
        a[i] = i * 2;
    for (int i = 0; i < n / 2; i++)
        a[i + n / 2] = i * 2 + 1;

    auto ans = power(a, k - 1);
    for (int i = 0; i < n; i++)
        std::cout << ans[i] + 1 << " \n"[i == n - 1];
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