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
    
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::map<int, int> pos;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        pos[a[i]] = i + 1;
    }

    std::sort(std::begin(a), std::end(a));
    std::vector<int> diff;
    for (int i = 0; i < n - 1; i++)
        diff.emplace_back(a[i + 1] - a[i]);

    if (n <= 3)
        std::cout << "1\n";
    else
    {
        std::map<int, int> m;
        for (auto d : diff)
            m[d]++;

        auto erase = [&](int x)
        {
            m[x]--;
            if (m[x] == 0)
                m.erase(x);
        };

        for (int i = 1; i < n - 1; i++)
        {
            int d1 = a[i] - a[i - 1];
            int d2 = a[i + 1] - a[i];
            int nd = a[i + 1] - a[i - 1];

            erase(d1);
            erase(d2);
            m[nd]++;

            if (std::size(m) == 1)
            {
                std::cout << pos[a[i]] << "\n";
                return 0;
            }

            erase(nd);
            m[d1]++;
            m[d2]++;
        }
            
        if (std::size(std::set(std::begin(diff), std::end(diff) - 1)) == 1)
            std::cout << pos[a.back()] << '\n';
        else if (std::size(std::set(std::begin(diff) + 1, std::end(diff))) == 1)
            std::cout << pos[a.front()] << '\n';
        else
            std::cout << "-1\n";
    }

    return 0;
}