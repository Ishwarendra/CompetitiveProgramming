#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

template<class T>
T power(T a, i64 b) 
{
    T res = 1;
    for (; b; b /= 2, a *= a) 
    {
        if (b % 2) 
            res *= a;
    }
    return res;
}

template<class T>
T inverse(T a, T m) 
{
    T u = 0, v = 1;
    while (a != 0) 
    {
        T t = m / a;
        m -= t * a; 
        u -= t * v; 
        std::swap(a, m);
        std::swap(u, v);
    }
    assert(m == 1);
    return u;
}

template<int P>
struct MInt 
{
    int x;
    constexpr MInt() : x{} {}
    constexpr MInt(i64 x) : x{norm(x % getMod())} {}
    
    static int Mod;
    constexpr static int getMod() 
    {
        if (P > 0) 
            return P;
        else 
            return Mod;
    }
    constexpr static void setMod(int Mod_) { Mod = Mod_; }
    constexpr int norm(int x) const 
    {
        if (x < 0) 
            x += getMod();
        
        if (x >= getMod()) 
            x -= getMod();
        
        return x;
    }
    constexpr int val() const { return x; }
    explicit constexpr operator int() const { return x; }
    constexpr MInt operator-() const 
    {
        MInt res;
        res.x = norm(getMod() - x);
        return res;
    }
    constexpr MInt inv() const 
    {
        assert(x != 0);
        return MInt(inverse(x, P));
    }
    constexpr MInt &operator*=(MInt rhs) & 
    {
        x = 1LL * x * rhs.x % getMod();
        return *this;
    }
    constexpr MInt &operator+=(MInt rhs) & 
    {
        x = norm(x + rhs.x);
        return *this;
    }
    constexpr MInt &operator-=(MInt rhs) & 
    {
        x = norm(x - rhs.x);
        return *this;
    }
    constexpr MInt &operator/=(MInt rhs) & 
    {
        return *this *= rhs.inv();
    }
    friend constexpr MInt operator*(MInt lhs, MInt rhs) 
    {
        MInt res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr MInt operator+(MInt lhs, MInt rhs) 
    {
        MInt res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr MInt operator-(MInt lhs, MInt rhs) 
    {
        MInt res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr MInt operator/(MInt lhs, MInt rhs) 
    {
        MInt res = lhs;
        res /= rhs;
        return res;
    }
    friend constexpr std::istream &operator>>(std::istream &is, MInt &a) 
    {
        i64 v;
        is >> v;
        a = MInt(v);
        return is;
    }
    friend constexpr std::ostream &operator<<(std::ostream &os, const MInt &a) { return os << a.val(); }
    friend constexpr bool operator==(MInt lhs, MInt rhs) { return lhs.val() == rhs.val(); }
    friend constexpr bool operator!=(MInt lhs, MInt rhs) { return lhs.val() != rhs.val(); }
};
 
template<>
int MInt<0>::Mod = 1;
 
template<int V, int P>
constexpr MInt<P> CInv = MInt<P>(V).inv();

constexpr int P = 998244353;
using Z = MInt<P>;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> pos(n);
    for (int i = 0; i < 2 * n; i++)  
    {
        int c;
        std::cin >> c;
        pos[c - 1].emplace_back(i);
    }

    n *= 2;

    std::vector<std::vector<int>> g(n), rg(n);
    for (int c = 0; c < n / 2; c++)
    {
        if (pos[c].empty())
            continue;

        for (int i = 1; i < std::size(pos[c]); i++)
        {
            int st = pos[c][i - 1];
            int en = pos[c][i];

            g[st].emplace_back(en);
            g[en].emplace_back(st);
            rg[st].emplace_back(en);
            rg[en].emplace_back(st);
        }

        int st = pos[c].front();
        int en = pos[c].back();

        for (int i = st + 1; i < en; i++)
        {
            rg[i].emplace_back(st);
            g[st].emplace_back(i);
        }
    }

    int t = 1;
    std::vector<int> tout(n), ord(n);
    auto dfs = [&](auto &&self, int u) -> void
    {
        ord[u] = 1;
        for (int v : g[u])
        {
            if (!ord[u])
                self(self, v);
        }
        tout[u] = t++;
    };

    for (int i = 0; i < n; i++)
    {
        if (!ord[i])
            dfs(dfs, i);
    }

    std::iota(std::begin(ord), std::end(ord), 0);
    std::sort(std::begin(ord), std::end(ord), [&](int u, int v)
    {
        return tout[u] > tout[v];
    });

    std::fill(std::begin(tout), std::end(tout), -1);
    std::vector<int> dp;
    auto rev_dfs = [&](auto &&self, int u, int scc_num) -> void
    {
        tout[u] = scc_num;
        if (std::size(dp) == scc_num)
            dp.emplace_back(1);
        else
            dp.back()++;

        for (int v : rg[u])
        {
            if (tout[v] == -1)
                self(self, v, scc_num);
        }
    };

    int cnt = 0;
    for (int u : ord)
    {
        if (tout[u] == -1)
            rev_dfs(rev_dfs, u, cnt++);
    }

    std::vector<int> indeg(cnt);
    for (int u = 0; u < n; u++)
    {
        for (int v : g[u])
        {
            if (tout[u] != tout[v])
                indeg[tout[v]]++;
        }
    }

    Z ans = 1;
    int min_sz = 0;
    for (int i = 0; i < cnt; i++)
    {
        if (indeg[i] == 0)
        {
            min_sz++;
            ans *= dp[i];
        }
    }

    std::cout << min_sz << " " << ans << "\n";
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