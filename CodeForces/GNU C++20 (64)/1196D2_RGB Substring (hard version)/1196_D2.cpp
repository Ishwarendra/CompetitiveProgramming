#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

bool find(std::string s, std::string pat)
{
    return s.find(pat) != std::string::npos;
}

void solve()
{
    int n, k;
    std::string s;
    std::cin >> n >> k >> s;

    if (k == 1)
    {
        std::cout << "0\n";
        return;
    }

    if (k == 2)
    {
        if (find(s, "RG") || find(s, "GB") || find(s, "BR"))
            std::cout << "0\n";
        else
            std::cout << "1\n";

        return;
    }

    std::map<char, std::array<std::vector<int>, 3>> m;
    for (char ch : std::string("RGB"))
    {
        for (int st = 0; st < 3; st++)
        {
            m[ch][st].resize(n);
            for (int i = st; i < n; i += 3)
                m[ch][st][i] += s[i] == ch;
        }
    }

    for (char ch : std::string("RGB"))
    {
        for (int st = 0; st < 3; st++)
        {
            for (int i = 1; i < n; i++)
                m[ch][st][i] += m[ch][st][i - 1];
        }
    }

    constexpr int inf = 1e9;

    auto get = [&](int st, std::string p)
    {
        if (st + k > n)
            return inf;

        auto &r = m[p[0]][st % 3];
        auto &g = m[p[1]][(st + 1) % 3];
        auto &b = m[p[2]][(st + 2) % 3];

        int tot = k;
        tot -= r[st + k - 1] - (st - 1 < 0 ? 0 : r[st - 1]);
        tot -= g[st + k - 1] - (st - 1 < 0 ? 0 : g[st - 1]);
        tot -= b[st + k - 1] - (st - 1 < 0 ? 0 : b[st - 1]);
        return tot;
    };

    int ans = inf;
    for (int i = 0; i < n; i++)
    {
        std::vector<std::string> ps {"RGB", "GBR", "BRG"};
        for (auto p : ps)
            ans = std::min(ans, get(i, p));
    }

    std::cout << ans << "\n";
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