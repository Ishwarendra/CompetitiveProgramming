#include<bits/stdc++.h>
 
#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif
 
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::string s;
 
    std::cin >> n >> k >> s;
 
    int st = -1;
    char ch = s[0];
 
    auto match = [&](int len)
    {
        std::string t1, t2;
 
        for (int i = 0; i < len; i++)
            t1 += s[i];
 
        for (int i = n - len; i < n; ++i)
            t2 += s[i];
 
        print(len, t1, t2);
 
        return t1 == t2;
    };
 
    for (int len = 1; len < n; len++)
    {
        if (match(len))
            st = len - 1;
    }
    
   
        std::string ans = s;
        
        for (int i = 0; i < k - 1; ++i)
            ans += s.substr(st + 1);
 
        std::cout << ans << "\n";
    
 
    return 0;
}