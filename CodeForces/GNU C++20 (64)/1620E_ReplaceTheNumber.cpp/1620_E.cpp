#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int N = 5e5 + 1;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int q;
    std::cin >> q;

    std::map<int, std::vector<int>> pos;
    int id = 0;

    while (q--)
    {
        int t;
        std::cin >> t;

        if (t == 1)
        {
            int x;
            std::cin >> x;

            pos[x].emplace_back(id++);
        }
        else
        {
            int x, y;
            std::cin >> x >> y;

            if (x == y)
                continue;

            if (std::size(pos[x]) > std::size(pos[y]))
            {
                pos[x].insert(std::end(pos[x]), std::begin(pos[y]), std::end(pos[y]));
                std::swap(pos[x], pos[y]);
                pos[x].clear();
            }
            else
            {
                pos[y].insert(std::end(pos[y]), std::begin(pos[x]), std::end(pos[x]));
                pos[x].clear();
            }
        }
    }

    std::vector<int> a(id);
    for (int i = 1; i <= N; i++)
    {
        for (auto index : pos[i])
            a[index] = i;
    }

    for (int i = 0; i < id; i++)
        std::cout << a[i] << " \n"[i == id - 1];
    
    return 0;
}