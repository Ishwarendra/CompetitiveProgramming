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

template <typename T>
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
struct MInt {
    int x;
    MInt() : x{} {}
    MInt(i64 x) : x{norm(x % P)} {}

    int norm(int x)
    {
        if (x < 0)
            x += P;
        if (x >= P)
            x -= P;
        return x;
    }
    constexpr int val() const { return x; }
    explicit constexpr operator int() const { return x; }
    MInt operator-() const
    {
        MInt res;
        res.x = norm(P - x);
        return res;
    }
    MInt inv() const
    {
        assert(x != 0);
        return MInt(inverse(x, P));
    }
    MInt &operator*=(const MInt &rhs)
    {
        x = 1LL * x * rhs.x % P;
        return *this;
    }
    MInt &operator+=(const MInt &rhs)
    {
        x = norm(x + rhs.x);
        return *this;
    }
    MInt &operator-=(const MInt &rhs)
    {
        x = norm(x - rhs.x);
        return *this;
    }
    MInt &operator/=(const MInt &rhs) { return *this *= rhs.inv(); }
    friend MInt operator*(const MInt &lhs, const MInt &rhs)
    {
        MInt res = lhs;
        res *= rhs;
        return res;
    }
    friend MInt operator+(const MInt &lhs, const MInt &rhs)
    {
        MInt res = lhs;
        res += rhs;
        return res;
    }
    friend MInt operator-(const MInt &lhs, const MInt &rhs)
    {
        MInt res = lhs;
        res -= rhs;
        return res;
    }
    friend MInt operator/(const MInt &lhs, const MInt &rhs)
    {
        MInt res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator>>(std::istream &is, MInt &a)
    {
        i64 v;
        is >> v;
        a = MInt(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const MInt &a) { return os << a.val(); }
    friend constexpr bool operator==(MInt lhs, MInt rhs) { return lhs.val() == rhs.val(); }
    friend constexpr bool operator!=(MInt lhs, MInt rhs) { return lhs.val() != rhs.val(); }
};
 
constexpr int P = 1e9 + 7;
using Z = MInt<P>;

struct Comb 
{
    int n;
    std::vector<Z> _fac;
    std::vector<Z> _invfac;
    std::vector<Z> _inv;
    
    Comb() : n{0}, _fac{1}, _invfac{1}, _inv{0} {}
    Comb(int n) : Comb() { init(n); }
    
    void init(int m) 
    {
        if (m <= n) return;
        _fac.resize(m + 1);
        _invfac.resize(m + 1);
        _inv.resize(m + 1);
        
        for (int i = n + 1; i <= m; i++) 
            _fac[i] = _fac[i - 1] * i;
        
        _invfac[m] = _fac[m].inv();
        for (int i = m; i > n; i--) 
        {
            _invfac[i - 1] = _invfac[i] * i;
            _inv[i] = _invfac[i] * _fac[i - 1];
        }
        n = m;
    }
    
    Z fac(int m) 
    {
        if (m > n) init(2 * m);
        return _fac[m];
    }
    Z invfac(int m) 
    {
        if (m > n) init(2 * m);
        return _invfac[m];
    }
    Z inv(int m) 
    {
        if (m > n) init(2 * m);
        return _inv[m];
    }
    Z binom(int n, int m) 
    {
        if (n < m || m < 0) return 0;
        return fac(n) * invfac(m) * invfac(n - m);
    }
} comb; 

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<int> adj[n];
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;

        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    std::vector<Z> dp(n, 1);
    std::vector<int> cnt(n, 1);

    std::function<void(int, int)> dfs;
    dfs = [&](int u, int p)
    {
        for (auto v : adj[u])
        {
            if (v == p)
                continue;

            dfs(v, u);
            cnt[u] += cnt[v];
            dp[u] *= comb.invfac(cnt[v]) * dp[v];
        }

        dp[u] *= comb.fac(cnt[u] - 1);
    }; dfs(0, 0);

    auto move = [&](int u, int p)
    {
        dp[p] *= comb.invfac(cnt[p] - 1) * dp[u].inv();
        cnt[p] -= cnt[u];
        dp[p] *= comb.fac(cnt[p] - 1);
        dp[p] *= comb.fac(cnt[u]);

        dp[u] *= comb.invfac(cnt[u] - 1) * dp[p];
        cnt[u] += cnt[p];
        dp[u] *= comb.fac(cnt[u] - 1);
        dp[u] *= comb.invfac(cnt[p]);
    };

    std::vector<Z> ans(n);
    dfs = [&](int u, int p)
    {
        ans[u] = dp[u];
        for (int v : adj[u])
        {
            if (v == p)
                continue;

            Z old_u = dp[u], old_v = dp[v];
            int cnt_u = cnt[u], cnt_v = cnt[v];
            move(v, u);

            dfs(v, u);

            dp[u] = old_u, dp[v] = old_v;
            cnt[u] = cnt_u, cnt[v] = cnt_v;
        }
    }; dfs(0, 0);

    for (int i = 0; i < n; i++)
        std::cout << ans[i] << "\n";
    
    return 0;
}