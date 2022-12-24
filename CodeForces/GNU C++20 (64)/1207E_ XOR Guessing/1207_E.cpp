#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int N = 100;
constexpr int M = 7;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    auto query = [](auto &a)
    {
        std::cout << "? ";
        for (auto i : a)
            std::cout << i << " ";
        std::cout << std::endl;

        int x;
        std::cin >> x;

        return x;
    };

    auto getBit = [](auto x, auto pos) { return (x >> pos) & 1; };
    auto setBit = [](auto x, auto pos) { return x | (1 << pos); };

    std::vector<int> a(N), b(N);
    for (int i = 0; i < 100; i++) 
    {
        a[i] = (1 << M) + (i + 1);
        for (int j = M; j < 2 * M; j++)
            a[i] = setBit(a[i], j);
    }
    for (int i = 0; i < 100; i++)
    {
        b[i] = (i + 1) << M;
        for (int j = 0; j < M; j++)
            b[i] = setBit(b[i], j);
    }

    std::array<int, 2> x{};
    x[1] = query(a);
    x[0] = query(b);

    int num = 0;

    for (int i = 0; i < M; i++) 
    {
        if (!getBit(x[0], i))
            num = setBit(num, i);
    }   

    for (int i = M; i < 2 * M; i++)
    {
        if (!getBit(x[1], i))
            num = setBit(num, i);
    }

    std::cout << "! " << num << std::endl;
        
    return 0;
}
