#include<bits/stdc++.h>


#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);

    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    std::vector<int> b = a;
    std::sort(b.begin(), b.end());

    std::vector<std::multiset<int>> group(k);

    for (int i = 0; i < k; i++)
    {
        for (int j = i; j < n; j += k)
            group[i].insert(a[j]);
    }
    
    for (int i = 0; i < n; i++)
    {
        int gr = i % k;

        if (group[gr].find(b[i]) == group[gr].end())
        {
            std::cout << "No\n";
            return 0;
        }
    }

    std::cout << "Yes\n";
    
    return 0;
}