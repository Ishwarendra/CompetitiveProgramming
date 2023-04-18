#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, d;
    std::cin >> n >> d;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    std::reverse(std::begin(a), std::end(a));
    std::vector<int> ans(n, n);

    std::queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            q.emplace(i);
            ans[i] = 0;
        }
    }

    while (!q.empty())
    {
        auto u = q.front();
        q.pop();

        int v = (u + d) % n;
        if (ans[v] == n)
        {
            ans[v] = ans[u] + 1;
            q.emplace(v);
        }
    }

    int max = *std::max_element(std::begin(ans), std::end(ans));

    if (max == n)
        std::cout << "-1\n";
    else
        std::cout << max << "\n";
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