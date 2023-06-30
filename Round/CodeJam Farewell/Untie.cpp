#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

void solve()
{
    std::string s;
    std::cin >> s;

    int n = std::size(s);
    // PP RR PP => PPPP RR
    char st = s[0];
    int j = n - 1;
    while (j >= 0 and s[j] == st)
        j--;

    if (j < 0)
    {
        // ceil(num / den) = (num + den - 1) / num  if (num >= 0 and den > 0)
        std::cout << (n + 1) / 2 << "\n";
        return;
    }   

    std::rotate(std::begin(s), std::begin(s) + j + 1, std::end(s));
    char ch = s[0];
    int cnt = 1;
    int ans = 0;

    for (int i = 1; i < n; i++)
    {
        if (s[i] == ch)
            cnt++;
        else
        {
            ans += cnt / 2;
            cnt = 1;
            ch = s[i];
        }
    }

    ans += cnt / 2;
    std::cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    for (int i = 1; i <= t; i++)
    {
        std::cout << "Case #" << i << ": ";
        solve();
    }
    
    return 0;
}