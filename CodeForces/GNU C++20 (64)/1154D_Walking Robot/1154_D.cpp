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
    
    int n, b, a;
    std::cin >> n >> b >> a;

    std::vector<int> s(n);
    for (int i = 0; i < n; i++)
        std::cin >> s[i];

    int rema = a, remb = b;
    int i = 0;
    // even after 0 acc can increase
    while (i < n and (rema or remb))
    {
        if (rema and !remb)
            rema--;
        else if (remb and !rema)
        {
            remb--;
            rema += s[i];
        }
        else
        {
            if (s[i] == 1 and rema < a)
                rema++, remb--;
            else if (s[i] == 1)
                rema--;
            else
                rema--;
        }

        i++;
    }

    std::cout << i << "\n";
    
    return 0;
}