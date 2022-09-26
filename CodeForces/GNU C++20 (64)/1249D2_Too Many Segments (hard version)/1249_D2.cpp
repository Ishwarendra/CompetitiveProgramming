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
    
    auto cmp = [&](auto &x, auto &y)
    {
        if (x.second != y.second)
            return x.second > y.second;
        return x.first < y.first;
    };

    int n, k;
    std::cin >> n >> k;

    constexpr int N = 2e5 + 10;

    std::map<std::pair<int, int>, std::vector<int>> pos;
    std::vector<std::pair<int, int>> a;
    std::vector<int> t(N);

    for (int i = 0; i < n; i++)
    {
        int l, r;
        std::cin >> l >> r;
        a.emplace_back(l, r);
        t[l]++, t[r + 1]--;

        pos[{l, r}].emplace_back(i + 1);
    }

    for (int i = 1; i < N; i++)
        t[i] += t[i - 1];

    for (int i = 0; i < N; i++)
    {

    }
    
    return 0;
}