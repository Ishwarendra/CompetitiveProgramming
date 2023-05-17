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
 
constexpr int P = 998244353;
using Z = MInt<P>;
constexpr int M = 2 * 3 * 11 * 37 * 23 * 97 + 1;

constexpr int N = 5e3 + 1;
std::vector<Z> pw(N), invPw(N);

std::vector<Z> getHash(std::string &s)
{
    int n = std::size(s);
    std::vector<Z> hash(n);

    hash[0] = s[0];
    for (int i = 1; i < n; i++)
        hash[i] = hash[i - 1] + s[i] * pw[i];

    return hash;
}

void solve()
{
    std::string s;
    std::cin >> s;  

    std::reverse(std::begin(s), std::end(s));
    auto rhash = getHash(s);
    std::reverse(std::begin(s), std::end(s));
    auto hash = getHash(s);

    int n = std::size(s);

    auto prefPalin = [&](int i)
    {
        Z hash1 = hash[i];
        Z hash2 = (rhash.back() - rhash[n - i - 2]) * invPw[n - 1 - i];
        return hash1 == hash2; 
    };

    auto suffPalin = [&](int i)
    {
        Z hash1 = (hash.back() - hash[i - 1]) * invPw[i];
        Z hash2 = rhash[n - 1 - i];
        return hash1 == hash2;
    };

    auto isPalin = [&](int i, int j)
    {
        Z hash1 = hash[i] + (hash.back() - hash[j - 1]) * invPw[j - i - 1];
        i = n - 1 - i;
        j = n - 1 - j;
        std::swap(i, j);

        Z hash2 = rhash[i] + (rhash.back() - rhash[j - 1]) * invPw[j - i - 1];
        return hash1 == hash2;
    };

    std::array ans { 0, n };
    for (int i = 0; i < n - 1; i++)
    {
        if (i + 1 > ans[0] + 1 + (n - ans[1]) and prefPalin(i))
            ans[0] = i, ans[1] = n;
    }

    for (int i = 1; i < n; i++)
    {
        if (n - i > ans[0] + 1 + (n - ans[1]) and suffPalin(i))
            ans[0] = -1, ans[1] = i;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (i - j > ans[0] - ans[1] and isPalin(i, j))
                ans = {i, j};
        }
    }

    auto [i, j] = ans;
    std::cout << s.substr(0, i + 1) + s.substr(j) << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    pw[0] = 1;
    for (int i = 1; i < std::size(pw); i++)
        pw[i] = pw[i - 1] * M;

    invPw[0] = 1, invPw[1] = pw[1].inv();
    for (int i = 2; i < N; i++)
        invPw[i] = invPw[i - 1] * invPw[1];

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}