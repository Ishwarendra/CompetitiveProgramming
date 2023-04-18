#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    const int max = (n - 1) / 2;

    std::vector a(n, std::vector(n, 0));
    
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < i + 1 + max; j++)
        {
            a[i][j % n] = 1;
            a[j % n][i] = -1;
        }
    }

    std::vector score(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
            std::cout << a[i][j] << " ";
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;

            if (a[i][j] == 1)
                score[i] += 3;
            else if (a[i][j] == 0)
                score[j] += 1;
        }
    }   

    assert(std::size(std::set(std::begin(score), std::end(score))) == 1);

    std::cout << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}