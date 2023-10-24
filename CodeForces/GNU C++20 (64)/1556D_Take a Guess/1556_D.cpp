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

    auto query = [&](std::string op, int i, int j)
    {
        std::cout << op << " " << i + 1 << " " << j + 1 << std::endl;
        int x;
        std::cin >> x;
        return x;
    };

    int n, k;
    std::cin >> n >> k;

    std::vector<i64> a(n);

    std::array<int, 3> c{};
    for (int i = 0; i < 3; i++)
    {
        int band = query("and", i, (i + 1) % 3);
        int bor = query("or", i, (i + 1) % 3);
        c[i] = band + bor;
    }

    i64 sum = (1LL + c[0] + c[1] + c[2]) / 2;
    a[0] = sum - c[1];
    a[1] = sum - c[2];
    a[2] = sum - c[0];

    for (int i = 3; i < n; i++)
    {
        int band = query("and", 0, i);
        int bor = query("or", 0, i);
        a[i] = band + bor - a[0];
    }
    
    std::sort(std::begin(a), std::end(a));
    std::cout << "finish " << a[k - 1];
    std::cout.flush();

    return 0;
}