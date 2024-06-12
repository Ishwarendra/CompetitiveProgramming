#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::string s;
    std::cin >> n >> s;
    
    std::string ans;
    auto turnOn = [&](int id)
    {
        ans += std::string(id + 1, 'A');
        if (id)
            ans += std::string(id, 'B');
    };
    
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '1')
            turnOn(i);
    }
    
    std::cout << std::size(ans) << "\n" << ans;
    
    return 0;
}