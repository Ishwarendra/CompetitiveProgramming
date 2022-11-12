#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::string s;
    std::cin >> n >> s;

    std::vector<std::array<int, 2>> diff;
    for (int i = 0; i < 2 * n; i += 2)
    {
        if (s[i] ^ s[i + 1])
        {
            if (s[i] == '1')
                diff.push_back({i + 1, i});
            else
                diff.push_back({i, i + 1});
        }
    }

    if (std::ssize(diff) % 2 or std::count(std::begin(s), std::end(s), '1') % 2)
    {
        std::cout << "-1\n";
        return;
    }

    if (diff.empty())
    {
        std::cout << "0\n";
        for (int i = 0; i < 2 * n; i += 2)
            std::cout << i + 1 << " \n"[i == 2 * n - 2];

        return;
    }

    std::vector<int> right_shift;
    int turn = 0;
    for (int i = 0; i < std::ssize(diff); i++)
    {
        right_shift.emplace_back(diff[i][turn]);
        turn ^= 1;
    }

    std::cout << std::ssize(right_shift) << " ";
    for (int i = 0; i < std::ssize(right_shift); i++)
        std::cout << right_shift[i] + 1 << " \n"[i == std::ssize(right_shift) - 1];

    char last = s[right_shift.back()];
    for (int i = 1; i < std::ssize(right_shift); i++)
        s[right_shift[i]] = s[right_shift[i - 1]];

    s[right_shift[0]] = last;

    for (int i = 0; i < 2 * n; i += 2)
        std::cout << i + 1 << " \n"[i == 2 * n - 2];
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