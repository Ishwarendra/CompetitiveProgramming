#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve(std::vector<int> &a, i64 k)
{
    int n = std::size(a);

    std::vector<i64> p(n);
    p[0] = a[0];
    for (int i = 1; i < n; i++)
        p[i] += p[i - 1] + a[i];

    auto getSum = [&](int l, int r) -> i64
    {
        if (l > r)
            return 0;

        i64 ans = p[r];

        if (l > 0)
            ans -= p[l - 1];

        return ans;
    };

    auto get = [&](int id, auto diff)
    {
        auto good = [&](int mid) -> bool
        {
            if (id - mid < 0 or id + mid - diff >= n)
                return false;

            i64 left = 1LL * mid * a[id] - getSum(id - mid, id - 1);
            i64 right = getSum(id, id + mid - diff) - 1LL * (mid - diff) * a[id];

            if (mid == 1)
                print(left, right, k)
            return left + right <= k;
        };

        int left = 1, right = std::min(id, n - 1 - id);
        int ans = 0;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (good(mid))
                ans = mid, left = mid + 1;
            else
                right = mid - 1;
        }

        return 1 + ans * 2 - diff; 
    };

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = std::max({ans, get(i, 0), get(i, 1)});
    }

    std::cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    i64 k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    solve(a, k);
    
    return 0;
}