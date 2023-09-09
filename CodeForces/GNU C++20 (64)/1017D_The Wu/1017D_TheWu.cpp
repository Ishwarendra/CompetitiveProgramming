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
    
    int n, len, q;
    std::cin >> n >> len >> q;

    std::vector<int> w(n);
    for (int i = 0; i < n; i++)
        std::cin >> w[i];

    auto getBit = [&](int x, int pos) { return x >> pos & 1; };
    auto wu = [&](int a, int b)
    {
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans += w[n - i - 1] * (getBit(a, i) == getBit(b, i));
        return ans;
    };

    std::map<int, int> m;
    for (int i = 0; i < len; i++)
    {
        std::string s;
        std::cin >> s;
        m[std::stoi(s, 0, 2)]++;
    }

    std::map<int, std::vector<int>> pos;

    std::vector cnt(1 << n, std::vector<i64>(101));
    for (int num = 0; num < (1 << n); num++)
    {
        for (auto [x, f] : m)
        {
            int cost = wu(num, x);
            if (cost <= 100)
                cnt[num][cost] += f;
        }
    }

    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 1; j <= 100; j++)
            cnt[i][j] += cnt[i][j - 1];
    }

    while (q--)
    {
        std::string s;
        int k;
        std::cin >> s >> k;

        int num = std::stoi(s, 0, 2);

        std::cout << cnt[num][k] << "\n";
    }
    
    return 0;
}