#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int MOD = 998244353;

// assume -MOD <= x < 2*MOD
int norm(int x) 
{
    if (x < 0) 
        x += MOD;
    
    if (x >= MOD) 
        x -= MOD;
    
    return x;
}
template<class T>
T power(T a, int b) 
{
    T res = 1;
    for (; b; b /= 2, a *= a) 
    {
        if (b % 2) 
            res *= a;
    }
    return res;
}
struct Z {
    int x;
    Z(int x = 0) : x(norm(x)) {}
    int val() const {
        return x;
    }
    Z operator-() const {
        return Z(norm(MOD - x));
    }
    Z inv() const {
        assert(x != 0);
        return power(*this, MOD - 2);
    }
    Z &operator*=(const Z &rhs) {
        x = (long long)(x) * rhs.x % MOD;
        return *this;
    }
    Z &operator+=(const Z &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    Z &operator-=(const Z &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    Z &operator/=(const Z &rhs) {
        return *this *= rhs.inv();
    }
    friend Z operator*(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res *= rhs;
        return res;
    }
    friend Z operator+(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res += rhs;
        return res;
    }
    friend Z operator-(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res -= rhs;
        return res;
    }
    friend Z operator/(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator>>(std::istream &is, Z &a) {
        int v;
        is >> v;
        a = Z(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Z &a) {
        return os << a.val();
    }
}; 

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector a(n, 0);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    for (int i = 1; i < n; i++)
    {
        if (a[i - 1] % a[i])
        {
            std::cout << "0\n";
            return;
        }
    }

    Z ans = 1;

    auto f = [&](int x, int y)
    {
        std::vector<int> pf;
        for (i64 i = 2; i * i <= x; i++)
        {
            int count = 0;
            while (x % i == 0)
                x /= i, count++;

            if (count)
                pf.emplace_back(i);
        }

        if (x > 1)
            pf.emplace_back(x);

        int sz = std::size(pf);
        Z res = 0;
        for (int i = 0; i < (1 << sz); i++)
        {
            int count = 1;
            i64 prod = 1;
            for (int j = 0; j < sz; j++)
            {
                if ((i >> j) & 1)
                    prod *= pf[j], count *= -1;
            }

            res += count * (m / (y * prod));
        }

        return res;
    };

    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[i - 1])
            ans *= m / a[i];
        else
        {
            // iterate over divisors of a[i - 1] / a[i]
            // Remove useless factors
            ans *= f(a[i - 1] / a[i], a[i]);
        }
    }

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