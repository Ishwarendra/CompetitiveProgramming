#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int N = 1e6 + 1;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::array<int, N> vis{};

    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        vis[a[i]]++;
    }

    std::sort(std::rbegin(a), std::rend(a));
    for (int i = N - 1; i > 0; i--)
    {
        if (vis[i])
            continue;

        int g = 0;
        for (int j = i; j < N; j += i)
        {
            if (vis[j])
                g = std::gcd(g, j);
        }

        if (g == i)
            vis[i] = 1;
    }

    int cnt = std::accumulate(std::begin(vis), std::end(vis), 0);
    std::cout << cnt - n;
    
    return 0;
}