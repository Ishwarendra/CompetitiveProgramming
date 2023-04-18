#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) if (n == 5 and m == 4) print(...);
#endif

using i64 = long long;

auto norm(std::vector<int> &a)
{
    for (auto &x : a)
        x = std::abs(x);
    std::sort(std::begin(a), std::end(a));
}

int solve(std::vector<int> a, std::vector<int> b)
{
    int n = std::size(a), m = std::size(b);
    if (n == 0 || m == 0)
        return 0;

    norm(a);
    norm(b);

    std::vector<int> already(m);
    for (int i = 0; i < m; i++)
    {
        bool present = std::binary_search(std::begin(a), std::end(a), b[i]);
        already[i] = (i - 1 >= 0 ? already[i - 1] : 0) + present;
    }

    int ans = 0;
    // print(a, b)
    for (int i = 0; i < m; i++)
    {
        // got boxes count strictly before b[i]
        int x = std::lower_bound(std::begin(a), std::end(a), b[i]) - std::begin(a);

        // find number of special positions in the range b[i] to b[i] + x - 1;
        int c1 = std::upper_bound(std::begin(b), std::end(b), b[i] + x - 1)     
                    - std::lower_bound(std::begin(b), std::end(b), b[i]);

        // find number of boxes B in the range b[i] to b[i] + x - 1;
        int B = std::upper_bound(std::begin(a), std::end(a), b[i] + x - 1)
                    - std::lower_bound(std::begin(a), std::end(a), b[i]);

        // find number of boxes in the range in the range b[i] + x to b[i] + x + B - 1;
        int c2 = std::upper_bound(std::begin(a), std::end(a), b[i] + x + B - 1)
                    - std::lower_bound(std::begin(a), std::end(a), b[i] + x);

        // find the number of boxes already at special position from 
        // b[i] + x + std::min(B, c2) to end
        int id = std::lower_bound(std::begin(b), std::end(b), b[i] + x + std::min(B, c2)) - std::begin(b);
        id--;

        int c3 = 0;
        if (id >= 0)
            c3 += already.back() - already[id];

        ans = std::max(ans, std::min(x, c1) + std::min(B, c2) + c3);
        // print(i, b[i], x, c1, B, c2, id, c3)
    }

    return ans;
}

std::vector<int> substr(std::vector<int> &a, int start, int len = -1)
{
    std::vector<int> ans;
    if (len == -1)
        ans = std::vector(std::begin(a) + start, std::end(a));
    else
        ans = std::vector(std::begin(a) + start, std::begin(a) + start + len);

    return ans;
}

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    for (int i = 0; i < m; i++)
        std::cin >> b[i];

    int sz_left1 = std::lower_bound(std::begin(a), std::end(a), 0) - std::begin(a);
    int sz_right1 = std::lower_bound(std::begin(b), std::end(b), 0) - std::begin(b);

    std::cout << solve(substr(a, 0, sz_left1), substr(b, 0, sz_right1)) +
              solve(substr(a, sz_left1), substr(b, sz_right1)) << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--)
        solve();

    return 0;
}