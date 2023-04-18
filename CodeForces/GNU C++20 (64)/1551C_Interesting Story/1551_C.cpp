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

    std::vector<std::string> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    auto get = [&](int num)  
    {
        std::sort(std::begin(a), std::end(a), [&](auto &x, auto &y)
        {
            std::array<int, 5> f1{}, f2{};
            for (auto ch : x) f1[ch - 'a']++;
            for (auto ch : y) f2[ch - 'a']++;

            return 2 * f1[num] - std::ssize(x) > 2 * f2[num] - std::ssize(y);
        });

        int total = 0, cnt = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            total += std::ssize(a[i]);
            std::array<int, 5> f1{};
            for (auto ch : a[i]) f1[ch - 'a']++;

            if (2 * (cnt + f1[num]) > total)
                ans++, cnt += f1[num];
            else
                break;
        }

        return ans;
    };

    int ans = 0;
    for (int i = 0; i < 5; i++)
        ans = std::max(ans, get(i));

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