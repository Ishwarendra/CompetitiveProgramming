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
    
    int n, m, h, k;
    std::string s;
    std::cin >> n >> m >> h >> k >> s;

    std::set<std::pair<int, int>> items;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        std::cin >> x >> y;
        items.emplace(x, y);
    }

    int x = 0, y = 0;
    std::map<char, std::array<int, 2>> dirs {{'R', {1, 0}}, {'L', {-1, 0}}, {'D', {0, -1}}, {'U', {0, 1}}};

    for (auto ch : s)
    {
        auto [dx, dy] = dirs[ch];
        x += dx;
        y += dy;
        h--;

        if (h < 0)
        {
            std::cout << "No";
            return 0;
        }
        
        if (items.count({x, y}) and h < k)
            h = k, items.erase({x, y});
    }

    std::cout << "Yes";
    
    return 0;
}