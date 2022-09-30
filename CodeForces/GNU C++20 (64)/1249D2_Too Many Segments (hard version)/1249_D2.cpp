#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int N = 2e5 + 10;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;

    std::vector<int> l(n), r(n);
    std::set<std::pair<int, int>, std::greater<>> seg;
    std::map<int, std::vector<int>> start, end;

    std::vector<int> ans;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> l[i] >> r[i];
        start[l[i]].emplace_back(i);
        end[r[i] + 1].emplace_back(i);
    }

    for (int i = 1; i < N; ++i)    
    {
        for (auto x : end[i]) // useless now since they end at i - 1 time
            seg.erase({r[x], x});

        for (auto x : start[i]) // new useful segments
            seg.emplace(r[x], x);

        int cnt = 0;
        while (seg.size() > k)
        {
            cnt++;
            auto [num, id] = *std::begin(seg);
            ans.emplace_back(id + 1);
            seg.erase(std::begin(seg));
        }
    }

    std::cout << std::size(ans) << "\n";
    for (auto i : ans)
        std::cout << i << " ";
    
    return 0;
}