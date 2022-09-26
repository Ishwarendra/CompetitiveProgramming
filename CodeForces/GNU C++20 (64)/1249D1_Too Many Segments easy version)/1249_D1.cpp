#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;

    std::map<std::pair<int, int>, std::vector<int>> m;
    std::vector<std::pair<int, int>> a(n);

    constexpr int N = 210;
    std::vector<int> t(N);

    for (int i = 0; i < n; i++) 
    {
        int l, r;
        std::cin >> l >> r;
        a[i] = {l, r};
        m[{l, r}].emplace_back(i + 1);

        t[l]++, t[r + 1]--;
    }

    std::sort(std::begin(a), std::end(a));
    for (int i = 1; i < N; i++)
        t[i] += t[i - 1];

    auto it = 0;
    std::vector<std::pair<int, int>> in_hand;
    std::vector<int> ans;

    for (int i = 0; i < N; ++i)
    {
        if (t[i] <= k)
            continue;
        int need = t[i] - k;

        for (; it < n and a[it].first <= i; it++)
            in_hand.push_back({a[it].second, a[it].first});
        std::sort(std::begin(in_hand), std::end(in_hand));

        while (need-- and !in_hand.empty())
        {
            auto [end, start] = in_hand.back();
            in_hand.pop_back();

            assert(std::size(m[{start, end}]));
            ans.push_back(m[{start, end}].back());
            m[{start, end}].pop_back();

            for (int i = start; i <= end; i++)
                t[i]--;
        }
    }

    std::cout << std::size(ans) << "\n";
    for (auto i : ans)
        std::cout << i << " ";
    
    return 0;
}