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

    std::vector<std::pair<int, int>> a, b;
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        if (x > 1)
            b.emplace_back(i, x);
        else
            a.emplace_back(i, x);
    }

    if (b.empty())
    {
        if (n == 1)
        {
            std::cout << "YES 0\n";
            std::cout << "0\n";
        }
        else if (n == 2)
        {
            std::cout << "YES 1\n";
            std::cout << "1\n1 2\n";
        }
        else
            std::cout << "NO\n";

        return 0;
    }

    std::map<int, int> rem;
    auto add = [&](int x, int num)
    {
        assert(rem[x] + num >= 0);
        rem[x] += num;
        if (rem[x] == 0)
            rem.erase(x);
    };

    std::vector<std::pair<int, int>> edges;
    for (int i = 1; i < std::size(b); i++)
    {
        edges.emplace_back(b[i].first, b[i - 1].first);   
        add(b[i].first, b[i].second - 1);
        add(b[i - 1].first, i == 1 ? b[i - 1].second - 1 : -1);
    }

    if (std::size(b) == 1)
        add(b.back().first, b.back().second);

    if (!a.empty())
    {
        edges.emplace_back(b.back().first, a.back().first);
        a.pop_back();
        add(b.back().first, -1);
    }

    if (!a.empty())
    {
        edges.emplace_back(b.front().first, a.back().first);
        a.pop_back();
        add(b.front().first, -1);
    }

    int dia = std::size(edges);

    for (int i = 0; i < std::size(a); i++)
    {
        if (rem.empty())
        {
            std::cout << "NO\n";
            return 0;
        }

        auto [num, f] = *std::begin(rem);
        edges.emplace_back(num, a[i].first);
        add(num, -1);
    }

    std::cout << "YES " << dia << "\n";
    std::cout << std::size(edges) << "\n";

    for (auto &[u, v] : edges)
        std::cout << u + 1 << " " << v + 1 << "\n";

    return 0;
}