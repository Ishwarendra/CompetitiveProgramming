#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<long long> a(2, 1);

    if (n == 1)
        std::cout << "1\n";
    else if (n == 2)
        std::cout << "1\n1 1\n";
    else
    {
        std::cout << "1\n1 1\n";
        n -= 2;
        while (n--)
        {
            int sz = a.size();
            std::vector<long long> b;

            b.push_back(a[0]);

            for (int i = 0; i < sz - 1; i++)
                b.push_back(a[i] + a[i + 1]);

            b.push_back(a.back());

            for (int x : b)
                std::cout << x << " ";
            std::cout << "\n";

            std::swap(a, b);
        }
    }

    return 0;
}