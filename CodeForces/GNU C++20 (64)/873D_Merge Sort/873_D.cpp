#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

std::vector<std::vector<int>> adj;
std::map<int, std::pair<int, int>> range;

int calls = 0;
auto mergeSort(std::vector<int> &a, int l, int r)
{
    calls++;
    if (std::is_sorted(std::begin(a) + l, std::begin(a) + r))
        return;

    int m = l + r >> 1;
    mergeSort(a, l, m);
    mergeSort(a, m, r);
    std::sort(std::begin(a) + l, std::begin(a) + r);
}

void dfs(int l, int r, int id)
{
    if (l >= r - 1)
    {
        range[id] = {l, r};
        return;
    }

    range[id] = {l, r};
    adj[id].emplace_back(2 * id + 1);
    adj[id].emplace_back(2 * id + 2);

    int m = (l + r) / 2;
    dfs(l, m, 2 * id + 1);
    dfs(m, r, 2 * id + 2);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    if (k % 2 == 0 or k > n * 2 - 1)
    {
        std::cout << -1;
        return 0;
    }

    adj.assign(4 << std::__lg(n), {});
    std::vector<int> cnt(4 << std::__lg(n), 1);
    dfs(0, n, 0);

    auto getCount = [&](auto self, int u, int p) -> void
    {
        for (int v : adj[u])
        {
            if (v == p)
                continue;

            self(self, v, u);
            cnt[u] += cnt[v];
        }
    }; getCount(getCount, 0, 0);

    for (auto &x : cnt)
        x--;

    int cur = 1;
    std::vector<int> toSort;
    auto work = [&](auto self, int u) -> void
    {
        if (cur == k)
        {
            toSort.emplace_back(u);
            return;
        }

        cur += 2 * !adj[u].empty();
        for (auto v : adj[u])
            self(self, v);
    }; work(work, 0);

    std::vector<int> ans(n);
    std::iota(std::begin(ans), std::end(ans), 1);
    std::reverse(std::begin(ans), std::end(ans));

    for (auto x : toSort)
    {
        auto [L, R] = range[x];
        std::sort(std::begin(ans) + L, std::begin(ans) + R);
    }

    for (int i = 0; i < n; i++)
        std::cout << ans[i] << " \n"[i == n - 1];
    mergeSort(ans, 0, n);
    print(calls, k, calls == k)

    return 0;
}