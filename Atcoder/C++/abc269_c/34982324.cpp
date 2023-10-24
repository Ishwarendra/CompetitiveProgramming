#include <bits/stdc++.h>

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
    
    std::vector<std::string> a(10);
    for (int i = 0; i < 10; i++)
        std::cin >> a[i];

    int st1 = 10, en1 = 10;
    int st2 = 0, en2 = 0;
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            if (a[i][j] == '#')
            {
                st1 = std::min(st1, i);
                en1 = std::min(en1, j);
                st2 = std::max(st2, i);
                en2 = std::max(en2, j);
            }
        }
    }
    st1++, en1++, st2++, en2++;
    std::cout << st1 << " " << st2 << "\n" << en1 << " " << en2 << "\n";
    return 0;
}