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
    
    int n;
    i64 x;
    std::cin >> n >> x;

    std::vector<int> d(n);
    for (int i = 0; i < n; i++)
        std::cin >> d[i];

    auto f = [&](auto x) { return 1LL * x * (x + 1) / 2; };

    std::vector<i64> p(n * 2), cnt(n * 2);
    for (int i = 0; i < n; i++)
    {
        p[i] = f(d[i]);
        cnt[i] = d[i];
        if (i > 0)
        {
            p[i] += p[i - 1];
            cnt[i] += cnt[i - 1];
        }

        p[i + n] = p[i];
        cnt[i + n] = cnt[i];
    }

    auto getId = [&](i64 rem, int left, int right)
    {
        int id = right + 1;
        int end = right;

        auto good = [&](int mid)
        {
            auto sum = cnt[end] - (mid ? cnt[mid - 1] : 0LL);
            return sum <= rem;
        };

        while (left <= right)
        {
            int mid = std::midpoint(left, right);
            if (good(mid))
                id = mid, right = mid - 1;
            else
                left = mid + 1;
        }

        return id;
    };

    auto get = [&](i64 rem, i64 ans) -> i64
    {
        int id = getId(rem, 0, n - 1);

        ans += p.back() - (id ? p[id - 1] : 0LL);
        rem -= cnt.back() - (id ? cnt[id - 1] : 0LL);

        if (id > 0)
            ans += f(d[id - 1]) - f(d[id - 1] - rem);

        return ans;
    };  

    i64 ans = get(x, 0);

    for (int i = n; i < n * 2; i++)
    {
        if (cnt[i] > x)
        {
            int id = getId(x, 0, i - n);
            i64 cur = p[i - n] - (id ? p[id - 1] : 0LL);
            if (id > 0)
            {
                i64 rem = x - (cnt[i - n] - (id ? cnt[id - 1] : 0LL));
                cur += f(d[id - 1]) - f(d[id - 1] - rem);
            }

            ans = std::max(ans, cur);
            continue;
        }

        i64 rem = x - cnt[i];
        i64 cur = p[i];
        ans = std::max(ans, get(rem, cur));
    }

    std::cout << ans;
    
    return 0;
}