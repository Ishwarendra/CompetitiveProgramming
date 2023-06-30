#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int N = 1e9 + 1;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q;
    std::cin >> n >> q;

    std::map<int, int> comp, decomp;
    std::vector upd(n, std::array<int, 3>());
    std::vector<int> coord { 0 };
    for (int i = 0; i < n; i++)
    {
        int l, r, v;
        std::cin >> l >> r >> v;
        // l++, r++;

        comp[l] = comp[r] = 0;
        upd[i] = {l, r, v};
        coord.emplace_back(l);
        coord.emplace_back(r);
    }   
    
    std::sort(std::begin(coord), std::end(coord));
    coord.erase(std::unique(std::begin(coord), std::end(coord)), std::end(coord));
    std::vector query(q, std::array<int, 2>());
    for (auto &[l, r] : query)
        std::cin >> l >> r;

    int pos = 1;
    for (auto &[num, f] : comp)
    {
        f = pos;
        decomp[pos] = num;
        pos++;
    }

    std::vector<i64> p(pos + 1);
    for (auto [l, r, v] : upd)
        p[comp[l]] += v, p[comp[r] + 1] -= v;

    for (int i = 1; i < pos + 1; i++)
        p[i] += p[i - 1];
        
    print(p)
    for (int i = 1; i < std::size(coord); i++)
    {
        int cur = coord[i];
        int prev = coord[i - 1];
        p[i] += p[i - 1] * (cur - prev);
    }

    print(p, coord)
    auto _get = [&](int x, int y)
    {
        return p[y] - p[x - 1];
    };

    auto get = [&](int x) { return _get(x, x); };

    auto notSmall = [&](int x)
    {
        int left = 1, right = pos - 1;
        int ans = -1;
        while (left <= right)
        {
            int mid = std::midpoint(left, right);
            if (decomp[mid] >= x)
                ans = mid, right = mid - 1;
            else
                left = mid + 1;
        }

        return ans;
    };

    auto notBig = [&](int x)
    {
        int left = 1, right = pos - 1;
        int ans = -1;

        while (left <= right)
        {
            int mid = std::midpoint(left, right);
            if (decomp[mid] <= x)
                ans = mid, left = mid + 1;
            else
                right = mid - 1;
        }

        return ans;
    };

    for (auto &[L, R] : query)
    {
        int l = notSmall(L);
        int r = notBig(R);
        i64 sum = 0;
        if (l <= r)
        {
            sum = _get(l, r);
            sum += 1LL * (decomp[l] - L + 1) * get(l);
            sum += 1LL * (R - decomp[r] + 1) * get(r);
        }
        else
            sum += 1LL * get(l) * (R - L + 1);

        std::cout << sum << "\n"; 
    }

    return 0;
}