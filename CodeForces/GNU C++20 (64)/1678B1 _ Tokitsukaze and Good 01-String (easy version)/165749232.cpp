#include <bits/stdc++.h>
 
#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif
 
using i64 = long long;
 
void solve()
{
    int n;
    std::cin >> n;
 
    std::string s;
    std::cin >> s;
 
    int cnt = 1;
    std::vector<int> a, odd;
 
    for (int i = 1; i < n; i++)  
    {
        if (s[i] != s[i - 1])
        {
            a.emplace_back(cnt);
            if (cnt % 2)
                odd.push_back((int) std::size(a) - 1);
 
            cnt = 1;
        }
        else
            cnt++;
    }
 
    a.emplace_back(cnt);
    if (cnt % 2)
        odd.push_back((int) std::size(a) - 1);
 
    cnt = 0;
    for (int i = 1; i < std::size(odd); i += 2)
        cnt += odd[i] - odd[i - 1];
 
    print(a)
    std::cout << cnt << "\n";
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