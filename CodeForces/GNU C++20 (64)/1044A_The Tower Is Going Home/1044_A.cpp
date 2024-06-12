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
    
    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> verti(n), hori;
    for (int i = 0; i < n; i++)
        std::cin >> verti[i];
    
    std::sort(std::begin(verti), std::end(verti));
    
    for (int i = 0; i < m; i++)
    {
        int x1, x2, y;
        std::cin >> x1 >> x2 >> y;
        
        if (x1 == 1)
            hori.emplace_back(x2);
    }
    
    std::sort(std::begin(hori), std::end(hori));
    m = std::size(hori);
    
    auto getHori = [&](int x)
    {
        auto id = std::lower_bound(std::begin(hori), std::end(hori), x) - std::begin(hori);
        return m - id;  
    };
    
    auto minHori = [&](int x)
    {
        auto it = std::lower_bound(std::begin(hori), std::end(hori), x);
        if (it == std::begin(hori))
            return 0;
        
        return *std::prev(it);
    };
    
    auto vertiLessThanEq = [&](int x)
    {
        int id = std::upper_bound(std::begin(verti), std::end(verti), x) - std::begin(verti);
        return id;  
    };
    
    int ans = n + m;
    if (hori.empty())
        ans = 0;
    else if (verti.empty())
        ans = std::count(std::begin(hori), std::end(hori), int(1e9));
    
    if (!hori.empty())
        ans = std::min<int>(ans, std::count(std::begin(hori), std::end(hori), int(1e9)) + n);

    for (int i = 0; i < n; i++)
    {
        int cur_ans = getHori(verti[i]);
        int closest = minHori(verti[i]);
        cur_ans += vertiLessThanEq(closest - 1);
        
        ans = std::min(ans, cur_ans);
    }
    
    std::cout << ans;
    
    return 0;
}