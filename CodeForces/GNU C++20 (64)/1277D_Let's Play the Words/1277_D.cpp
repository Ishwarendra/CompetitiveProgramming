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
    std::cin >> n;

    std::array<int, 4> cnt{};
    std::vector<std::string> a(n);
    std::map<std::string, int> pos;
    std::map<int, std::vector<int>> extra;

    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        pos[a[i]] = i;
    }

    std::sort(std::begin(a), std::end(a));
    for (auto s : a)
    {
        auto t = std::string(1, s.back()) + s.front();

        std::reverse(std::begin(s), std::end(s));
        if (s.front() != s.back() and !std::binary_search(std::begin(a), std::end(a), s))
        {
            std::reverse(std::begin(s), std::end(s));
            extra[std::stoi(t, nullptr, 2)].emplace_back(pos[s]);
        }
        else
            cnt[std::stoi(t, nullptr, 2)]++;
    }

    int ans = cnt[2] + std::ssize(extra[2]) - cnt[1] - std::ssize(extra[1]);
    int id = 2;
    if (ans < 0)
    {
        std::swap(cnt[2], cnt[1]);
        id = 1;
        ans = -ans;
    }
 
    if (cnt[0] > 0 and cnt[3] > 0 and (cnt[1] + cnt[2] + std::size(extra[1]) + std::size(extra[2])) == 0)
    {
        std::cout << "-1\n";
        return;
    }

    if (ans <= 1)
    {
        std::cout << 0 << '\n';
        return;
    }

    ans /= 2;
    std::cout << ans << "\n";
    // print(std::ssize(extra[id]), ans, id, extra[1], extra[2])
    assert(ans <= std::size(extra[id]));
    while (ans--)
    {
        std::cout << extra[id].back() + 1 << " ";
        extra[id].pop_back();
    }

    std::cout << "\n";
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