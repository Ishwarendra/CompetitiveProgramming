#include <bits/stdc++.h>
 
#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif
 
using i64 = long long;
 
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s;
    std::cin >> s;
 
    int n = std::size(s);
    std::vector<int> vis(3);
 
    for (int i = 0; i < n; )
    {
        char cur = s[i];
        if (vis[cur - 'a'] or (cur - 'a' > 0 and !vis[cur - 'a' - 1]))
        {
            std::cout << "NO\n";
            return 0;
        }
        vis[cur - 'a'] = 1;
        while (i < n and s[i] == cur)
            i++;
    }
 
    std::fill(std::begin(vis), std::end(vis), 0);
    for (char ch : s)
        vis[ch - 'a']++;
 
    if (vis[2] != vis[0] and vis[2] != vis[1] or *std::min_element(std::begin(vis), std::end(vis)) == 0)
        std::cout << "NO\n";
    else
        std::cout << "YES\n";
    
    return 0;
}