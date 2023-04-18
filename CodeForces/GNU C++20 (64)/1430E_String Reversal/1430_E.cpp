#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

template <typename T>
struct Fenwick 
{
    const int n;
    std::vector<T> a;
    
    Fenwick() {}
    Fenwick(int n) : n(n), a(n, T()) {}
    template <class G>
    Fenwick(const std::vector<G> in) : Fenwick(std::ssize(in))
    {
        for (int i = 1; i <= n; i++)
        {
            a[i - 1] += in[i - 1];
            if (i + (i & -i) <= n)
                a[i - 1 + (i & -i)] += a[i - 1];
        }
    }
    
    void add(int x, T v) 
    {
        for (int i = x + 1; i <= n; i += i & -i) 
            a[i - 1] += v;
    }
    
    T sum(int x) 
    {
        auto ans = T();
        for (int i = x + 1; i > 0; i -= i & -i) 
            ans += a[i - 1];
        return ans;
    }
    
    T rangeSum(int l, int r) 
    { 
        if (l > r)
            return T(0);
        return sum(r) - sum(l - 1); 
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::string s;
    std::cin >> n >> s;

    std::vector<int> pos[26], it(26);
    for (int i = 0; auto ch : s)
        pos[ch - 'a'].emplace_back(i++);

    auto b = s;
    std::reverse(std::begin(b), std::end(b));

    Fenwick<int> ft(n);
    i64 ans = 0;
    for (int i = 0; i < n; i++)
    {
        char ch = b[i];
        int where = pos[ch - 'a'][it[ch - 'a']];
        int sub = ft.sum(where - 1);

        ans += where - sub;

        ft.add(where, 1);
        it[ch - 'a']++;
    }

    std::cout << ans;
    
    return 0;
}