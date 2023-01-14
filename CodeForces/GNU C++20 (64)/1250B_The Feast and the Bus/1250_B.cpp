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
    
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(k);
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        a[x - 1]++;
    }

    std::sort(std::begin(a), std::end(a));

    auto good = [&](i64 mid) -> std::pair<bool, int>
    {
        int count = 0;
        int i = 0, j = k - 1;

        while (i <= j)
        {
            assert(a[j] <= mid);

            count++;
            if (a[i] + a[j] <= mid)
                i++, j--;
            else if (a[j] <= mid)
                j--;
        }

        return {true, count};
    };

    i64 ans = 1e18;
    int max = a.back() + (std::ssize(a) > 1 ? a[k - 2] : 0);
    int min = a.back();

    for (int mid = max; mid >= min; mid--)
    {
        auto [g, count] = good(mid);
        if (g)
        {
            print(mid, count)
            ans = std::min(ans, 1LL * count * mid);
        }
        else
            break;
    }

    std::cout << ans;
    
    return 0;
}