#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::string s;
    std::cin >> n >> s;

    auto get = [&](int need) -> std::pair<int, std::string>
    {
        int tot = n / need;
        if (tot > 26)
            return {n, ""};

        std::vector<std::vector<int>> pos(26);
        for (int i = 0; i < n; i++)
            pos[s[i] - 'a'].emplace_back(i);

        std::pair<int, std::string> cur{};
        std::vector<std::pair<int, int>> donor, taker;

        std::vector<int> ord(26);
        std::iota(std::begin(ord), std::end(ord), 0);
        std::sort(std::begin(ord), std::end(ord), [&](const int &i, const int &j)
        {
            int f1 = std::min<int>(need, std::size(pos[i]));
            int f2 = std::min<int>(need, std::size(pos[j]));
            return f1 > f2;
        });

        int id = -1;
        for (int ch : ord)
        {
            if (tot == 0)
                break;

            id++;
            if (!pos[ch].empty())
            {
                tot--;
                if (need == std::ssize(pos[ch]))
                    continue;

                if (need > std::ssize(pos[ch]))
                    taker.emplace_back(need - std::ssize(pos[ch]), ch);
                else
                    donor.emplace_back(std::ssize(pos[ch]) - need, ch);
            }
            else
            {
                tot--;
                taker.emplace_back(need, ch);
            }
        }

        for (int i = id + 1; i < 26; i++)
        {
            int ch = ord[i];
            if (!pos[ch].empty())
                donor.emplace_back(std::size(pos[ch]), ch);
        }

        int op = 0;
        auto t = s;
        auto update = [&](int ch1, int ch2, int cnt)
        {
            op += cnt;
            while (cnt--)
            {
                t[pos[ch1].back()] = char('a' + ch2);
                pos[ch2].emplace_back(pos[ch1].back());
                pos[ch1].pop_back();
            }
        };


        while (!donor.empty() and !taker.empty())
        {   
            auto [can_give, chd] = donor.back();
            auto [can_take, cht] = taker.back();

            donor.pop_back();
            taker.pop_back();

            int min = std::min(can_give, can_take);
            update(chd, cht, min);
            can_give -= min;
            can_take -= min;

            if (can_give)
                donor.emplace_back(can_give, chd);
            if (can_take)
                taker.emplace_back(can_take, cht);
        }

        return { op, t };
    };

    std::pair<int, std::string> ans{n, ""};
    for (int i = 1; i <= n; i++)
    {
        if (n % i)
            continue;

        ans = std::min(ans, get(n / i));
    }

    std::cout << ans.first << "\n" << ans.second << "\n";
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