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

    std::vector<int> a(n), extra(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    auto bound = [&](int x)
    {
        return 1 <= x and x <= n;
    };

    std::map<int, int> m;
    for (int i = 0; i < n; i++)
        m[a[i]]++;

    std::vector<int> missing;
    for (int i = 1; i <= n; i++)
    {
        if (!m.contains(i))
            missing.emplace_back(i);
    }

    constexpr int N = 2e5 + 10;
    std::bitset<N> ignored;
    int count = std::size(missing);

    for (int i = 0, j = 0; i < n and j < count; i++)
    {
        if (m[a[i]] > 1)
        {
            if (a[i] <= n and a[i] < missing[j] and !ignored[a[i]])
                ignored[a[i]] = 1;
            else
            {
                m[a[i]]--;
                a[i] = missing[j];
                m[a[i]]++;
                j++;
            }
        }
    }

    std::cout << count << "\n";
    for (int i = 0; i < n; i++)
        std::cout << a[i] << " \n"[i == n - 1];
    
    return 0;
}