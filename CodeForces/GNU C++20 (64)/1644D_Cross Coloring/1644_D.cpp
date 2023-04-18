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

void solve()
{
    int n, m, k, q;
    std::cin >> n >> m >> k >> q;

    std::vector<std::pair<int, int>> query(q); 
    for (auto &[x, y] : query)
        std::cin >> x >> y;

    std::reverse(std::begin(query), std::end(query));

    std::map<int, int> row, col;
    std::array<int, 2> filled{};
    for (int pos = 0; auto [x, y] : query)
    {
        if (!row.contains(x) and filled[1] < m)
            row[x] = pos, filled[0]++; 

        if (!col.contains(y) and filled[0] < n)
            col[y] = pos, filled[1]++;

        pos++;
    }
    
    std::set<int> s;
    for (auto &[_, num] : row)
        s.emplace(num);
    for (auto &[_, num] : col)
        s.emplace(num);

    int count = std::size(s);

    std::cout << power<Z>(k, count) << "\n";
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