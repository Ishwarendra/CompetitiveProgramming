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

    std::array<int, 26> freq{};
    for (int i = 0; auto ch : s)
        freq[ch - 'a']++;

    std::pair<int, std::string> ans{n, ""};
    for (int i = 1; i <= n; i++)
    {
        if (n % i)
            continue;

        int need = n / i;
        std::vector<std::vector<int>> pos(26);
        for (int i = 0; i < n; i++)
            pos[s[i] - 'a'].emplace_back(i);

        std::pair<int, std::string> cur{};
        print(i)
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