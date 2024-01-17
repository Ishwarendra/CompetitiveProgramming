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

    std::string s, t;
    std::cin >> s >> t;

    std::string prev(2, '!');
    int ans = 0;
    for (int i = 0; i < n; i++)  
    {
        int reset = 0;
        if (s[i] == t[i])
        {
            if (s[i] == '0')
                ans += 1 + (prev == "11"), reset = prev == "11";
            else
                ans += prev == "00", reset = prev == "00";
        }
        else
            ans += 2;

        if (reset)
            prev = "!!";
        else
            prev[0] = s[i], prev[1] = t[i];

    }

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