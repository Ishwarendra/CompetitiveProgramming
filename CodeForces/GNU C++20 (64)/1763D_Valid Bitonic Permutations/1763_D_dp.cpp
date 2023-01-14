#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int MOD = 1e9 + 7;

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
    int n, left, right, x, y;
    std::cin >> n >> left >> right >> x >> y;
    left--, right--, x--, y--;

    std::vector dp(n, std::vector<Z>(n, 0));

    auto disp = [&]()
    {
        for (auto p : dp)
        {
            for (auto xy : p)
                std::cout << xy << " ";
            std::cout << "\n";
        }
    };

    for (int i = 1; i < n - 1; i++)    
    {
        if (((i == left and n - 1 == x) or (i != left)) and ((i == right and n - 1 == y) or (i != right)))
            dp[i][i] = 1;
    }

    for (int len = 1; len <= n; len++)
    {
        for (int i = 0; i + len - 1 < n; i++)
        {
            int j = i + len - 1;
            int to_put = n - (j - i + 1);
            
            if (i + 1 < n)
            {
                if (((i == left and to_put == x) or (i != left and to_put != x)) 
                    and ((i == right and to_put == y) or (i != right and to_put != y)))
                    dp[i][j] += dp[i + 1][j];
            }
            if (j - 1 >= 0)
            {
                if (((j == left and to_put == x) or (j != left and to_put != x)) 
                    and ((j == right and to_put == y) or (j != right and to_put != y)))
                    dp[i][j] += dp[i][j - 1];
            }
        }
    }

    // disp();

    std::cout << dp[0][n - 1] << "\n";
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