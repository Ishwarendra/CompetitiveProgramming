#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::multiset<std::pair<int, int>> m;
    std::vector<std::vector<int>> pos(n + 1);
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        a[i] = x;
        pos[x].emplace_back(i);
    }

    int max = 1;
    for (int i = 2; i < n; i++)
    {
        if (std::size(pos[i]) > std::size(pos[max]))
            max = i;
    }

    std::vector<int> ans(n);
    int num = 1;
    while (!pos[max].empty())
    {
        while (pos[num].empty() or num == max)
            num++;

        if (num > n)
            break;

        ans[pos[max].back()] = num;
        ans[pos[num].back()] = max;
        pos[num].pop_back();
        pos[max].pop_back();
    }

    std::vector<int> id;
    for (int i = 1; i <= n; i++)
    {
        for (int j : pos[i])
            id.emplace_back(j);
    }

    int sz = std::size(id);
    for (int i = 0; i < sz; i++)
        ans[id[(i + 1) % sz]] = a[id[i]];

    for (int i = 0; i < n; i++)
        std::cout << ans[i] << " \n"[i == n - 1];
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