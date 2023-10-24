#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::string s;
    std::cin >> n >> k >> s;  

    int odd_need = (n - k) % 2;
    std::array<int, 26> f{};

    for (auto ch : s)
        f[ch - 'a']++;

    if (odd_need == 0)
    {
        for (int i = 0; i < 26; i++)
            k -= f[i] % 2;

        std::cout << (k >= 0 and k % 2 == 0 ? "YES\n" : "NO\n");
    }
    else
    {
        auto get = [&](int ch)
        {
            int k_ = k;
            for (int i = 0; i < 26; i++)
            {
                if (i != ch)
                    k_ -= f[i] % 2;
                else
                    k_ -= f[i] % 2 == 0;
            }

            return k_ >= 0 and k_ % 2 == 0;        
        };

        for (auto ch = 0; ch < 26; ch++)
        {
            if (get(ch))
            {
                std::cout << "YES\n";
                return;
            }
        }

        std::cout << "NO\n";
    }
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