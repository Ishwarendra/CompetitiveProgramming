#include <bits/stdc++.h>

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

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
        
    std::vector<std::array<Z, 2>> dp(61, {0, 0});
    dp[2][0] = 0, dp[2][1] = 1;

    std::function<Z(int, int)> C = [&](int n, int r) -> Z
    {
        if (r < 0 or n <= 0)
            return Z(0);
        if (r == 0)
            return Z(1);
        return n * C(n - 1, r - 1) / r;
    };

    dp[2][0] = 0, dp[2][1] = 1;
    for (int i = 4; i <= 60; i++)
    {
        dp[i][1] = dp[i - 2][0] + C(i - 1, i / 2 - 1);
        dp[i][0] = dp[i - 2][1] + C(i - 2, i / 2 - 2);
    }

    int t;
    std::cin >> t;

    while (t--)
    {
        int n;
        std::cin >> n;

        std::cout << dp[n][1] << " " << dp[n][0] << " " << "1\n";
    }

    return 0;
}