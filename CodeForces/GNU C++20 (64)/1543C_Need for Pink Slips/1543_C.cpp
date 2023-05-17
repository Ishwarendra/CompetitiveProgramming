#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;
using l64 = long double;

constexpr l64 eps = 1e-14;

void solve()
{
    std::array<l64, 3> prob;
    l64 v;
    for (int i = 0; i < 3; i++)
        std::cin >> prob[i];
    std::cin >> v;

    l64 ans = 0, cur_ans = 1;
    std::string s;
    std::function<void(std::array<l64, 3> &, int, int)> f;
    f = [&](std::array<l64, 3> &p, int id, int len)
    {
        if (len > 23)
            return;

        if (id == 2)
        {
            if (cur_ans > eps)
            {
                cur_ans *= p[id];
                ans += len * cur_ans;
                cur_ans /= p[id];
            }
            return;
        }

        auto np = p;
        auto old = cur_ans;
        cur_ans *= p[id];
        std::array valid {p[0] > eps, p[1] > eps, p[2] > eps};
        int id1 = (id + 1) % 3, id2 = (id + 2) % 3;
        int cnt = valid[id1] + valid[id2];
        l64 add = std::min(p[id], v) / cnt;

        if (valid[id1])
            p[id1] += add;
        if (valid[id2])
            p[id2] += add;

        p[id] -= std::min(p[id], v);

        for (int i = 0; i < 3; i++)
        {
            if (p[i] > eps)
                f(p, i, len + 1);
        }

        p = np;
        cur_ans = old;
    };

    f(prob, 0, 1);
    f(prob, 1, 1);
    f(prob, 2, 1);

    std::cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cout << std::fixed << std::setprecision(12);

    int t;
    std::cin >> t;

    while (t--)
        solve();

    return 0;
}