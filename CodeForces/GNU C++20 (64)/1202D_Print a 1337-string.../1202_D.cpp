#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>

int findMax(int n)
{
    int left = 1, right = 1e5;
    int ans = 0;
    while (left <= right)
    {
        int mid = std::midpoint(left, right);
        if (1LL * mid * (mid - 1) <= 2 * n)
            ans = mid, left = mid + 1;
        else
            right = mid - 1;
    }

    return ans;
}

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> need;
    while (n)
    {
        int max = findMax(n);
        n -= max * (max - 1) / 2;
        need.emplace_back(max);
    }

    need.emplace_back(0);
    std::reverse(std::begin(need), std::end(need));

    std::string ans(1, '1');
    for (int i = 1; i < std::size(need); i++)
    {
        int d = need[i] - need[i - 1];
        ans += std::string(d, '3') + "7";
    }

    std::cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--)
        solve();

    return 0;
}
