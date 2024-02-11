#include "bits/stdc++.h"

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

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::set<std::pair<int, int>> seg, s;
    int len = 1, prev = a[0];

    for (int i = 1; i < n; i++)
    {
        if (prev == a[i])
            len++;
        else
        {
            seg.emplace(-len, i - len);
            s.emplace(i - len, len);
            prev = a[i];
            len = 1;
        }
    }

    seg.emplace(-len, n - len);
    s.emplace(n - len, len);
    int ans = 0;

    while (!seg.empty())
    {
        auto [l, id] = *std::begin(seg);
        seg.erase(std::begin(seg));

        l = -l;
        auto it = s.find({id, l});

        if (it != std::begin(s) and std::next(it) != std::end(s))
        {
            auto [id_p, len_p] = *std::prev(it);
            auto [id_n, len_n] = *std::next(it);

            if (a[id_p] == a[id_n])
            {
                s.erase({id_p, len_p});
                s.erase({id_n, len_n});
                s.emplace(id_p, len_p + len_n);

                seg.erase({-len_p, id_p});
                seg.erase({-len_n, id_n});
                seg.emplace(-len_p - len_n, id_p);
            }
        }

        s.erase({id, l});
        ans++;
    }

    std::cout << ans;

    return 0;
}

