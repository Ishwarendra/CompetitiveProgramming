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

    std::map<i64, std::vector<std::pair<int, int>>> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)    
            m[p[j] - p[i]].emplace_back(i + 1, j);
    }

    for (auto &[num, segs] : m)
    {
        std::sort(std::begin(segs), std::end(segs), [&](auto &x, auto &y)
        {
            return x.second < y.second; 
        });
    }

    int ans = 0;
    std::vector<std::pair<int, int>> path;
    for (auto &[nums, seg] : m)
    {
        int cur_ans = 0;
        std::vector<std::pair<int, int>> cur_path;

        int end = -1;
        for (auto [l, r] : seg)
        {
            if (l <= end)
                continue;

            cur_ans++;
            end = r;
            cur_path.emplace_back(l, r);
        }

        if (cur_ans > ans)
        {
            ans = cur_ans;
            path = cur_path;
        }
    }

    std::cout << ans << "\n";
    for (auto [l, r] : path)
        std::cout << l << " " << r << "\n";

    return 0;
}