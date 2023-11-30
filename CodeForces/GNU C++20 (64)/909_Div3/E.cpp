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

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    int max = *std::max_element(std::begin(a), std::end(a));
    int min = *std::min_element(std::begin(a), std::end(a));

    int id = std::find(std::begin(a), std::end(a), min) - std::begin(a);
    for (int i = id + 1; i < n; i++)
    {
        if (a[i] == min and a[i - 1] != min)
        {
            std::cout << "-1\n";
            return;
        }
    }

    if (std::is_sorted(std::begin(a) + id, std::end(a)))
        std::cout << id << "\n";
    else
        std::cout << "-1\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}