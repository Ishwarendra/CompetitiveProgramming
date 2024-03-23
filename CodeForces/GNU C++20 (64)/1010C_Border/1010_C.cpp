#include <iostream>
#include <numeric>
#include <set>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    int g = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        std::cin >> a;

        g = std::gcd(g, a);
    }

    std::set<int> ans;
    for (int i = 0; i < k; i++)
        ans.emplace((1LL * g * i) % k);

    std::cout << std::size(ans) << "\n";
    for (auto it = std::begin(ans); it != std::end(ans); it++)
        std::cout << (*it) << " \n"[it == std::prev(std::end(ans))];

    return 0;
}
