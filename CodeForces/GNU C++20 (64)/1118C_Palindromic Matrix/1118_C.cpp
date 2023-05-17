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

    std::map<int, int> m_;
    for (int i = 0; i < n * n; i++)
    {
        int x;
        std::cin >> x;
        m_[x]++;
    }

    std::multiset<std::pair<int, int>, std::greater<>> m;
    std::vector<std::array<int, 4>> b[5];
    for (auto [num, f] : m_)
        m.emplace(f, num);

    std::vector a(n, std::vector(n, 0));

    int st = 0, en = n - 1;
    int num = 0;
    while (st <= en)
    {
        int i = 0, j = n - 1;
        while (i <= j)
        {
            int need = 4;
            if (i == j and st == en)
                need = 1;
            else if (i == j or st == en)
                need = 2;

            a[st][i] = a[en][i] = a[st][j] = a[en][j] = num;
            b[need].push_back({st, en, i, j});
            num++;
            i++, j--;
        }
        st++, en--;
    }

    for (int x : {4, 2, 1})
    {
        for (auto [st, en, i, j] : b[x])
        {
            auto [f, num] = *std::begin(m);
            m.erase(std::begin(m));
            if (f < x)
            {
                std::cout << "NO\n";
                return 0;
            }

            f -= x;
            m.emplace(f, num);

            a[st][i] = a[en][i] = a[st][j] = a[en][j] = num;
        }
    }

    std::cout << "YES\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            std::cout << a[i][j] << " \n"[j == n - 1];
    }
    
    return 0;
}