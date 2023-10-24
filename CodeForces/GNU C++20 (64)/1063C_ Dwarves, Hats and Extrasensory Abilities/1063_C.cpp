#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

std::string flip(std::string a)
{
    if (a == "white") 
        return "black";
    return "white";
}

std::string query(int x)
{
    std::cout << x << " " << 0 << std::endl;
    std::string s;
    std::cin >> s;

    return s;
}

constexpr int inf = 1e9;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    int rev = 0;
    auto s = query(0);

    std::map<std::string, std::vector<int>> m;
    if (s == "white")
    {
        rev = 1;
        m[flip(s)].emplace_back(0);
    }
    else
        m[s].emplace_back(0);

    n--;
    int left = 1, right = inf;
    while (n--)
    {
        int mid = std::midpoint(left, right);
        s = query(mid);
        if (rev) 
            s = flip(s);

        m[s].emplace_back(mid);
        if (s == "black")
            left = mid + 1;
        else
            right = mid - 1;
    }

    for (auto &[_, p] : m)
        std::sort(std::begin(p), std::end(p));

    auto &a = m["white"], b = m["black"];
    if (a.empty() || b.empty())
        std::cout << inf << " 0 " << inf << " 1" << std::endl;
    else
    {
        std::array<int, 2> max{};
        max[0] = a.back();
        max[1] = b.back();
        if (max[0] > max[1])
        {
            std::swap(a, b);
            std::swap(max[0], max[1]);
        }

        int min = b[0];
        assert(min > max[0]);
        if (max[0] + 1 != min)
            std::cout << max[0] + 1 << " 1 " << max[0] + 1 << " 2" << std::endl;
        else
            std::cout << min << " 1 " << (min + 1) << " 3" << std::endl; 
    }

    return 0;
}