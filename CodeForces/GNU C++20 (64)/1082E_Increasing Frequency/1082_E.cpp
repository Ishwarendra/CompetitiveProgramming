#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

int kadane(std::vector<int> &a)
{
    int max = 0, cur = 0;
    for (int i = 0; i < std::size(a); i++)
    {
        cur += a[i];
        if (cur < 0)
            cur = 0;
        max = std::max(max, cur);
    }

    return max;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, c;
    std::cin >> n >> c;

    std::vector<int> a(n), cnt(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        cnt[i] += a[i] == c;
        if (i > 0)
            cnt[i] += cnt[i - 1];
    }

    const int max = *std::max_element(std::begin(a), std::end(a));
    std::vector<std::vector<int>> pos(max + 1);

    for (int i = 0; i < n; i++)
        pos[a[i]].emplace_back(i);

    auto get = [&](int x, auto &pos)
    {
        std::vector<int> b;
        if (pos[0])
            b.emplace_back(-cnt[pos[0] - 1]);

        for (int i = 0; i + 1 < std::size(pos); i++)
        {
            b.emplace_back(1);
            int x_cnt = cnt[pos[i + 1] - 1] - cnt[pos[i]];
            b.emplace_back(-x_cnt);
        }

        b.emplace_back(1);
        if (cnt.back() - cnt[pos.back()])
            b.emplace_back(-(cnt.back() - cnt[pos.back()]));
        
        return kadane(b);
    };

    int ans = cnt.back();
    for (int num = -1; auto &x : pos)
    {
        num++;
        if (x.empty() or num == c)
            continue;
        ans = std::max(ans, get(num, x) + cnt.back());
        // print(ans, num)
    }

    std::cout << ans;

    return 0;
}