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
    
    std::string s;
    std::cin >> s;

    int cnt = std::count(std::begin(s), std::end(s), 'Q');
    int left = 0;

    int ans = 0;
    for (int i = 0; i < std::size(s); i++)
    {
        left += s[i] == 'Q';
        if (s[i] == 'A')
        {
            int right = cnt - left;
            ans += left * right;
        }
    }

    std::cout << ans;
    
    return 0;
}