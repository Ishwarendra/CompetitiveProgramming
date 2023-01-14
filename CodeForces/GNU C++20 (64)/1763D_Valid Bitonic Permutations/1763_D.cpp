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

constexpr int N = 110;
std::vector<Z> fact(N);

Z C(int n, int r)
{
    if (n < 0 or r < 0 or r > n)
        return Z(0);

    if (r == 0)
        return Z(1);

    return fact[n] / fact[r] / fact[n - r];
}

void solve()
{
    int n, left, right, x, y;
    std::cin >> n >> left >> right >> x >> y;
    x--, y--, left--, right--;

    if (x > y)
    {
        std::swap(x, y);
        int nleft = n - right - 1;
        int nright = n - left - 1;

        left = nleft, right = nright;
    }

    Z ans = 0;
    Z first = 0, second = 0;

    // 1 "2" 4 8 7 "6" 5 3 
    for (int pivot = left + 1; pivot < right; pivot++)
    {
        std::array<int, 3> type{}, rem{};
        type[0] = x;
        type[1] = (y - 1) - (x + 1) + 1;
        type[2] = (n - 2) - (y + 1) + 1;

        rem[0] = left;
        rem[1] = (n - right - 1) - (type[0] - rem[0]);
        rem[2] = (right - 1) - (pivot + 1) + 1;

        first += C(type[0], rem[0]) * C(type[1], rem[1]) * C(type[2], rem[2]);
        print(C(type[2], rem[2]).x, pivot)
    }

    // 1 "2" 3 "4" 5 6 0 -1 -2
    for (int pivot = right + 1; pivot < n - 1; pivot++)
    {
        std::array<int, 3> type{}, rem{};
        type[0] = x; 
        type[1] = (y - 1) - (x + 1) + 1;
        type[2] = (n - 2) - (y + 1) + 1;

        rem[0] = left;
        rem[1] = right - left - 1;
        rem[2] = pivot - right - 1;

        second += C(type[0], rem[0]) * C(type[1], rem[1]) * C(type[2], rem[2]);
        // print(C(type[0], rem[0]).x, type, rem)
    }

    // right is pivot
    if (y == n - 1)
    {
        first = 0;
        second = 0;
        if (right < n - 1)
            first = C(x, left) * C(y - x - 1, right - left - 1);
    }

    std::cout << first + second << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    fact[0] = 1;
    for (int i = 1; i < N; i++)
        fact[i] = fact[i - 1] * i;

    int t = 1;
    std::cin >> t;

    while (t--)
        solve();

    return 0;
}