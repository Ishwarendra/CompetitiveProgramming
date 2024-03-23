#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];
    for (int i = 0; i < n; i++)
        std::cin >> b[i];

    std::sort(std::begin(a), std::end(a));
    std::sort(std::begin(b), std::end(b));

    auto find = [&](auto &p, int x)
    {
        return std::binary_search(std::begin(p), std::end(p), x);
    };

    std::vector<int> both, left, right;
    for (int i = 1; i <= n; i++)
    {
        if (find(a, i) and find(b, i))
            both.emplace_back(i);
        else if (find(a, i))
            left.emplace_back(i);
        else
            right.emplace_back(i);
    }

    std::vector<int> l, r;
    while (!left.empty() and !right.empty() and k)
    {
        l.emplace_back(left.back());
        l.emplace_back(left.back());
        r.emplace_back(right.back());
        r.emplace_back(right.back());
        left.pop_back();
        right.pop_back();
        k--;
    }

    for (int i = 0; k > 0 and i + 1 < std::size(both); i += 2)
    {
        l.emplace_back(both[i]);
        l.emplace_back(both[i + 1]);
        r.emplace_back(both[i]);
        r.emplace_back(both[i + 1]);
        k--;
    }

    int sz = std::size(l);
    for (int i = 0; i < sz; i++)    
        std::cout << l[i] << " \n"[i == sz - 1];
    for (int i = 0; i < sz; i++)    
        std::cout << r[i] << " \n"[i == sz - 1];
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