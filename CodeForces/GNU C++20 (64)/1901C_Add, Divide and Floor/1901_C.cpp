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
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];
    
    std::set<int> b(std::begin(a), std::end(a));
    std::vector<int> ans;
    while (std::size(b) > 1)
    {
        std::set<int> c;
        int min = *std::begin(b);
        int max = *std::prev(std::end(b));
        
        int x = 0;
        if (min % 2 and max % 2 == 0)
            x = 1;
        
        for (auto ele : b)
            c.emplace((ele + x) / 2);
        ans.emplace_back(x);
        std::swap(c, b);
    }
    
    std::cout << std::size(ans) << "\n";
    for (int i = 0; i < std::size(ans) and std::size(ans) <= n; i++)
        std::cout << ans[i] << " \n"[i == std::ssize(ans) - 1];
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