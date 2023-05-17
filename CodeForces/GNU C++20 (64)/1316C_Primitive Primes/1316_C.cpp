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

    int n, m, p;
    std::cin >> n >> m >> p;

    std::vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    for (int i = 0; i < m; i++)
        std::cin >> b[i];

    const int P = p;

    std::vector<int> pa, pb;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % P)
            pa.emplace_back(i);
    }

    for (int i = 0; i < m; i++)
    {
        if (b[i] % P)
            pb.emplace_back(i);
    }

    int id1 = 0, id2 = 0;
    i64 num = 0;
    for (int i = 0; i <= pa[id1] + pb[id2]; i++)
    {
        if (i >= n or pa[id1] + pb[id2] - i >= m or pa[id1] + pb[id2] - i < 0)
            continue;

        num += (1LL * a[i] * b[pa[id1] + pb[id2] - i]) % P;
        num %= P;
    }

    if (num)
    {
        std::cout << pa[id1] + pb[id2] << "\n";
        return 0;
    }

    assert(false);

    return 0;
}