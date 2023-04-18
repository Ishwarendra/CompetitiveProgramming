#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    template<typename L, typename R>
    size_t operator()(std::pair<L, R> const& Y) const
    {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(Y.first * 31ull + Y.second + FIXED_RANDOM);
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::vector<i64> p(n + 1);
    for (int i = 0; i < n; i++)
        p[i + 1] = p[i] + a[i];

    std::set<i64> s;
    for (int i = 0; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
            s.emplace(p[j] - p[i]);
    }

    std::vector<int> path;
    int ans = 0;
    for (auto sum : s)
    {
        std::vector<int> dp(n + 1), skip(n + 1), par(n + 1, 0);
        std::map<i64, int> lastPos;
        lastPos[0] = 0;

        for (int i = 1; i <= n; i++)
        {
            if (lastPos.contains(p[i] - sum))
            {
                if (dp[lastPos[p[i] - sum]] + 1 > dp[i])
                    dp[i] = dp[lastPos[p[i] - sum]] + 1, par[i] = lastPos[p[i] - sum];
            }

            if (dp[i] < dp[i - 1])
            {
                dp[i] = dp[i - 1];
                par[i] = i - 1;
                skip[i] = 1;
            }

            lastPos[p[i]] = i;
        }

        int cur_ans = *std::max_element(std::begin(dp), std::end(dp));
        if (cur_ans <= ans)
            continue;

        path.clear();
        ans = cur_ans;

        for (int i = n; i >= 0 and cur_ans; )
        {
            if (dp[i] == cur_ans and !skip[i])
            {
                cur_ans--;
                path.emplace_back(i);
                path.emplace_back(par[i] + 1);
                i = par[i];
            }
            else
                i--;
        }
    }

    std::reverse(std::begin(path), std::end(path));
    std::cout << ans << "\n";
    for (int i = 0; i < std::size(path); i += 2)
        std::cout << path[i] << " " << path[i + 1] << "\n";

    return 0;
}