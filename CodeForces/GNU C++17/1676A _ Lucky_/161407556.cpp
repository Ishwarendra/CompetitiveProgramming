/*
    Author:  ishwarendra
    Created: 2022-06-21 21:08:02
*/
 
#include <bits/stdc++.h>
 
#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif
 
void solve()
{
    std::string s;
    std::cin >> s;
 
    std::cout << (s[0] + s[1] + s[2] == s[3] + s[4] + s[5] ? "Yes\n" : "No\n");
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