#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

struct Staircase
{
    std::map<int, int> m;
    void insert(int x, int y)
    {
        auto st = m.lower_bound(x);
        auto end = st;

        while (end != std::end(m) and end->second >= y)
            end++;
        m.erase(st, end);
        if (!m.count(x))
            m[x] = y;
    }   

    bool find(int x, int y)
    {
        auto it = m.lower_bound(x);
        if (it == std::begin(m))
            return false;

        it--;
        return it->second < y;
    }   
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::map<int, Staircase> m;
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        std::cin >> x >> y;

        if (i == 0)
            m[1].insert(x, y);
        else
        {
            int l = 1, r = ans;
            int id = 0;
            while (l <= r)
            {
                int mid = (l + r) / 2;
                if (m[mid].find(x, y))
                    l = mid + 1, id = mid;
                else
                    r = mid - 1;
            }

            ans = std::max(ans, id + 1);
            m[id + 1].insert(x, y);
        }
    }

    std::cout << ans;
    
    return 0;
}