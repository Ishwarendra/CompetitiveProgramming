#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

const std::set vowels {'a', 'e', 'i', 'o', 'u'};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;

    std::vector<std::string> a(4 * n);
    for (int i = 0; i < 4 * n; i++)
        std::cin >> a[i];

    auto startId = [&](std::string &s, int k_)
    {
        for (int i = std::ssize(s) - 1; i >= 0; i--)
        {
            if (vowels.count(s[i]))
                k_--;

            if (k_ == 0)
                return i;
        }

        return -1;
    };

    auto rhymes = [&](auto &s, auto &t)
    {
        std::array st {startId(s, k), startId(t, k)};
        if (st[0] == -1 or st[1] == -1)
            return false;

        return s.substr(st[0]) == t.substr(st[1]);
    };

    auto aabb = [&](int id)
    {
        return rhymes(a[id], a[id + 1]) and rhymes(a[id + 2], a[id + 3]);
    };

    auto abab = [&](int id)
    {
        return rhymes(a[id], a[id + 2]) and rhymes(a[id + 1], a[id + 3]);
    };

    auto abba = [&](int id)
    {
        return rhymes(a[id], a[id + 3]) and rhymes(a[id + 1], a[id + 2]);
    };

    auto getRhyme = [&](int id)
    {
        std::array<std::function<bool(int)>, 3> functions {aabb, abab, abba};

        int which = 0;
        for (int i = 0; i < 3; i++)
        {
            if (functions[i](id))
                which |= (1 << i);
        }

        if (which == 0)
            return std::string("NO");
        else if (which == 1) 
            return std::string("aabb");
        else if (which == 2)
            return std::string("abab");
        else if (which == 4)
            return std::string("abba");

        return std::string("aaaa");
    };

    auto merge = [](std::string a, std::string b)
    {
        if (a == b)
            return a;
        if (a == "aaaa")
            return b;
        else if (b == "aaaa")
            return a;
        
        return std::string("NO");
    };

    std::string ans(4, 'a');
    for (int i = 0; i < 4 * n; i += 4)
        ans = merge(ans, getRhyme(i));

    std::cout << ans;
    
    return 0;
}