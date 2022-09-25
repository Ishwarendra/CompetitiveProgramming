#include<bits/stdc++.h>
 
#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif
 
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int n;
    std::cin >> n;
 
    std::vector<int> p(n), q(n, -1);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> p[i];
        p[i]--;
    }
 
    std::vector<std::vector<int>> cycles;
    std::vector<bool> vis(n);
 
    std::function<std::vector<int>(int)> next = [&](int i)
    {
        std::vector<int> cyc;
 
        while (!vis[i])
            cyc.push_back(p[i]), vis[i] = true, i = p[i];
 
        return cyc;
    };
 
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            cycles.push_back(next(i));
    }
 
    std::sort(cycles.begin(), cycles.end(), [&](std::vector<int> &a, std::vector<int> &b)
    {
        if (a.size() % 2 == b.size() % 2)
            return a.size() < b.size();
 
        return (a.size() % 2) < (b.size() % 2);
    });
 
    auto mod = [&](int x, int m)
    {
        return (x + m) % m;
    };
 
    auto mergeToEven = [&](std::vector<int> &a, std::vector<int> &b)
    {
        assert(a.size() == b.size());
        int m = a.size();
 
        std::vector<int> ans(m * 2);
 
        for (int i = 0; i < m; ++i)
        {
            ans[2 * i] = a[i];
            ans[2 * i + 1] = b[i];
        }
 
        m *= 2;
        for (int i = 0; i < m; i++)
            q[ans[i]] = ans[mod(i + 1, m)];
    };
 
    auto makeOdd = [&](std::vector<int> &a)
    {
        int m = a.size();
        assert(m % 2 == 1);
 
        std::vector<int> ans(m);
 
        for (int i = 0, j = 0; j < m; i += 2, j++)
            ans[i % m] = a[j];
 
        for (int i = 0; i < m; ++i)
            q[ans[i]] = ans[mod(i + 1, m)];
    };
 
    int odd_st = 0, even_st = 0;
 
    for (int i = 0; i < cycles.size(); i++)
        odd_st += cycles[i].size() % 2 == 1;
 
    even_st = cycles.size() - odd_st;
 
    if ((even_st) % 2 == 1)
    {
        std::cout << "-1\n";
        return 0;
    }
 
    for (int i = 0; i < even_st; i += 2)
    {
        int n1 = cycles[i].size(), n2 = cycles[i + 1].size();
 
        if (n1 != n2)
        {
            std::cout << "-1\n";
            return 0;
        }
        else
            mergeToEven(cycles[i], cycles[i + 1]);
    }
 
    for (int i = even_st; i < cycles.size(); i++)
        makeOdd(cycles[i]);
 
    if (*std::min_element(q.begin(), q.end()) == -1)
        std::cout << "-1\n";
    else
    {
        for (int ele : q)
            std::cout << ele + 1 << " ";
        std::cout << "\n";
 
        for (int i = 0; i < n; i++)
            assert(q[q[i]] == p[i]);
    }
 
    return 0;
}