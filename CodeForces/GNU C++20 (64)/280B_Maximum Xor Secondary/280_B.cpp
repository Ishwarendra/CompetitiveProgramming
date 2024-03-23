#include <iostream>
#include <stack>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::stack<int> s;
    s.emplace(a[0]);

    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        ans = std::max(ans, s.top() ^ a[i]);
        while (!s.empty() and s.top() < a[i])
        {
            s.pop();

            if (!s.empty())
            {
                // std::cerr << s.top() << " " << a[i] << "\n";
                ans = std::max(ans, s.top() ^ a[i]);
            }
        }

        s.emplace(a[i]);
    }

    std::cout << ans << "\n";
}
