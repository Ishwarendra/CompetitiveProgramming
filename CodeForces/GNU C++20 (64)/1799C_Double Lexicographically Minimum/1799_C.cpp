#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    std::string s;
    std::cin >> s;

    std::array<int, 26> cnt{};
    for (auto ch : s)
        cnt[ch - 'a']++;

    const int n = std::size(s);
    std::string ans(n, '.');

    std::array<int, 2> sort{};
    for (int i = 0, j = n - 1, ch = 0; ch < 26; ch++)
    {
        if (!cnt[ch])
            continue;

        while (cnt[ch] > 1)
            cnt[ch] -= 2, ans[i++] = ans[j--] = char(ch + 'a');

        if (cnt[ch] == 0)
            continue;

        std::array<int, 2> diff{};
        for (int k = 25; k > ch; k--)
        {
            if (!cnt[k])
                continue;

            diff[0]++;
            diff[1] = k;
        }

        if (diff[0] > 1)
        {
            ans[j--] = char(ch + 'a');
            cnt[ch]--;
            sort = {i, j};
            for (int id = i; id <= j; id++)
            {
                for (int k = 0; k < 26; k++)
                {
                    if (cnt[k])
                    {
                        cnt[k]--, ans[id] = char(k + 'a');
                        break;
                    }
                }
            }

            break;
        }
        else if (diff[0] == 1)
        {
            while (cnt[diff[1]])
            {
                ans[i++] = char(diff[1] + 'a');
                cnt[diff[1]]--;
                if (cnt[diff[1]])
                    ans[j--] = char(diff[1] + 'a'), cnt[diff[1]]--;
            }

            if (i <= j)
                ans[j--] = char(ch + 'a'), cnt[ch] = 0;
        }
        else
            ans[i] = char(ch + 'a'), cnt[ch] = 0;
    }

    std::sort(std::begin(ans) + sort[0], std::begin(ans) + sort[1] + 1);
    if (std::string(std::rbegin(ans), std::rend(ans)) > ans)
        ans = std::string(std::rbegin(ans), std::rend(ans));

    std::cout << ans << "\n";
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