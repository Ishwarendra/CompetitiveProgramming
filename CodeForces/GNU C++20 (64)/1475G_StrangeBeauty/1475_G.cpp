#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

std::vector<int> factor(int n)
{
    std::vector<int> f;
    for (int i = 2; 1LL * i * i <= n; i++)
    {
        if (n % i)
            continue;

        f.emplace_back(i);
        if (i * i != n)
            f.emplace_back(n / i);
    }
    f.emplace_back(1);
    std::sort(std::begin(f), std::end(f));

    return f;
}

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::map<int, int> m;
    for (int i = 0; i < n; i++)
    {  
        std::cin >> a[i];
        m[a[i]]++;
    }

    std::sort(std::begin(a), std::end(a));
    int ans = n - 1;

    std::vector<int> dp(1 + a.back());

    for (auto [num, f] : m)
    {
        auto fac = factor(num);

        for (auto d : fac)
            dp[num] = std::max(dp[num], dp[d] + f);
    }

    std::cout << n - (*std::max_element(std::begin(dp), std::end(dp))) << "\n";
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