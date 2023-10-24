#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    int p = 0;
    std::vector<int> c(4);

    for (int x : a)
    {
        c[0]++;

        for (int j = 3; j >= 0; j--)
        {
            if (c[j])
            {
                if (j + x < 4)
                    c[j + x] += c[j], c[j] = 0;
                else
                    p += c[j], c[j] = 0;
            }
        }
    }

    std::cout << p << "\n";
    
    return 0;
}