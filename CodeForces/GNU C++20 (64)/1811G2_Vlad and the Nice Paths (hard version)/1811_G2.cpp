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
struct MInt 
{
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

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)      
        std::cin >> a[i];

    std::vector freq(n + 1, std::vector(n, 0));
    for (int i = 0; i < n; i++)
        freq[a[i]][i]++;

    for (int i = 0; i <= n; ++i)
    {
        for (int j = 1; j < n; j++)
            freq[i][j] += freq[i][j - 1];
    }

    std::vector dp2(n + 1, -1);
    std::function<int(int)> max = [&](int st) -> int
    {
        // ((max_path_length) starting at index-st) / k
        if (st >= n)
            return 0;
        if (dp2[st] != -1)
            return dp2[st];

        dp2[st] = 0;
        for (int end = st; end < n; end++)
        {
            int f_ai = freq[a[st]][end] - (st - 1 < 0 ? 0 : freq[a[st]][st - 1]);
            if (f_ai >= k)
                dp2[st] = std::max(dp2[st], 1 + max(end + 1));
        }

        return dp2[st];
    };

    int max_path = 0;
    for (int i = 0; i < n; i++)
        max_path = std::max(max_path, max(i));

    // max_freq_element ki frequency < k
    if (max_path == 0)
    {
        std::cout << "1\n";
        return;
    }

    constexpr int N = 5e3 + 1;
    std::bitset<N> done;
    std::vector<Z> dp(n);

    std::function<Z(int)> f = [&](int st) -> Z
    {
        if (st >= n)
            return 1;
        if (done[st])
            return dp[st];

        done[st] = 1;
        for (int end = st; end < n; end++)
        {
            int f_ai = freq[a[st]][end] - (st - 1 < 0 ? 0 : freq[a[st]][st - 1]);
            if (f_ai >= k and (max(st) - max(end + 1)) * k == k)
                dp[st] += comb.binom(f_ai - 1, k - 1) * f(end + 1);
        }

        return dp[st];
    };

    Z ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (max(i) == max_path)
            ans += f(i);
    }

    // if (n == 5 and k == 2) for (int i = 0; i < n; i++)
    //     std::cout << f(i) << " \n"[i == n - 1];

    std::cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}

// T = 10^6
// N = 10^8

// T * log(N)