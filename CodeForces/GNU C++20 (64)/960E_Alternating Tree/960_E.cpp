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

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::vector<int> adj[n];
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;

        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    std::vector<Z> dp(n);
    std::vector<int> cnt(n, 1);
    std::function<void(int, int, int)> dfs;

    dfs = [&](int u, int p, int sgn)
    {
        dp[u] = sgn * a[u];
        for (int v : adj[u])
        {
            if (v == p)
                continue;

            dfs(v, u, -sgn);
            cnt[u] += cnt[v];
            dp[u] += dp[v] + Z(cnt[v]) * a[u] * sgn;
        }
    }; dfs(0, 0, 1);

    auto move = [&](int u, int p, int sgn)
    {
        cnt[p] -= cnt[u];
        dp[p] -= dp[u] + Z(cnt[u]) * a[p];
        dp[p] *= -1;

        dp[u] *= -1;
        cnt[u] += cnt[p];
        dp[u] += dp[p] + Z(cnt[p]) * a[u];
    };

    Z ans = 0;
    dfs = [&](int u, int p, int sgn)
    {
        ans += dp[u];
        for (int v : adj[u])
        {
            if (v == p)
                continue;

            auto old_u = dp[u], old_v = dp[v];
            auto cnt_u = cnt[u], cnt_v = cnt[v];

            move(v, u, sgn);
            dfs(v, u, sgn);

            dp[u] = old_u, dp[v] = old_v;
            cnt[u] = cnt_u, cnt[v] = cnt_v;
        }
    }; dfs(0, 0, 1);

    std::cout << ans;
    
    return 0;
}