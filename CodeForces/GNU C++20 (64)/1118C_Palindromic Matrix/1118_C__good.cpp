#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;

auto row(auto &b)
{
    auto a = b;
    int n = std::size(a);
    for (int i = 0, j = n - 1; i < j; i++, j--)
        std::swap(a[i], a[j]);

    return a;
}

auto col(auto &b)
{
    auto a = b;
    int n = std::size(a);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            a[i][j] = b[n - 1 - i][n - 1 - j];
    }

    return a;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::map<int, int> m;
    for (int i = 0; i < n * n; i++)
    {
        int x;
        std::cin >> x;
        m[x]++;
    }

    std::vector a(n, std::vector<int>(n));

    auto getNum = [&](int freq)
    {
        std::array<int, 2> ans{ -1, inf};
        for (auto [num, f] : m)
        {
            if ((ans[0] == -1 and f >= freq) or (f >= freq and f < ans[1]))
                ans[0] = num, ans[1] = f;
        }

        if (m.contains(ans[0]) and m[ans[0]] == freq)
            m.erase(ans[0]);

        m[ans[0]] -= freq;
        return ans[0];
    };

    int st = n / 2, en = n / 2;
    if (n % 2 == 0)
        st--;

    while (st >= 0)
    {
        int i = 0, j = n - 1;
        while (i <= j)
        {
            int need = 4;
            if (st == en and i == j)
                need = 1;
            else if (st == en || i == j)
                need = 2;
            a[st][i] = a[st][j] = a[en][i] = a[en][j] = getNum(need);
            i++, j--;

            if (a[st][i] == -1)
            {
                std::cout << "NO\n";
                return 0;
            }
        }

        st--, en++;
    }

    // assert(a == row(a) and a == col(a));

    std::cout << "YES\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            std::cout << a[i][j] << " \n"[j == n - 1];
    }

    return 0;
}