#include <algorithm>
#include <iostream>
#include <vector>

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        a[i]--;
    }

    std::vector<int> vis(n);
    int ans = n, sub = 0;
    for (int i = 0; i < n; i++)
    {
        if (vis[i])
            continue;

        int u = i, cnt = 0;
        std::vector<int> nodes;
        while (!vis[u])
        {
            vis[u] = 1;
            nodes.emplace_back(u);
            u = a[u];
            cnt++;
        }

        ans--;

        std::sort(std::begin(nodes), std::end(nodes));
        for (int i = 1; i < std::size(nodes); i++)
            sub |= (nodes[i] - nodes[i - 1] == 1);
    }

    std::cout << ans - (sub ? 1 : -1) << "\n";
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
