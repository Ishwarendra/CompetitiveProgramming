#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

template<class T>
class Frac {
public:
    T num;
    T den;
    Frac(T num, T den) : num(num), den(den) {
        if (den < 0) {
            den = -den;
            num = -num;
        }
    }
    Frac() : Frac(0, 1) {}
    Frac(T num) : Frac(num, 1) {}
    double toDouble() const {
        return 1.0 * num / den;
    }
    Frac &operator+=(const Frac &rhs) {
        num = num * rhs.den + rhs.num * den;
        den *= rhs.den;
        return *this;
    }
    Frac &operator-=(const Frac &rhs) {
        num = num * rhs.den - rhs.num * den;
        den *= rhs.den;
        return *this;
    }
    Frac &operator*=(const Frac &rhs) {
        num *= rhs.num;
        den *= rhs.den;
        return *this;
    }
    Frac &operator/=(const Frac &rhs) {
        num *= rhs.den;
        den *= rhs.num;
        if (den < 0) {
            num = -num;
            den = -den;
        }
        return *this;
    }
    friend Frac operator+(Frac lhs, const Frac &rhs) {
        return lhs += rhs;
    }
    friend Frac operator-(Frac lhs, const Frac &rhs) {
        return lhs -= rhs;
    }
    friend Frac operator*(Frac lhs, const Frac &rhs) {
        return lhs *= rhs;
    }
    friend Frac operator/(Frac lhs, const Frac &rhs) {
        return lhs /= rhs;
    }
    friend Frac operator-(const Frac &a) {
        return Frac(-a.num, a.den);
    }
    friend bool operator==(const Frac &lhs, const Frac &rhs) {
        return lhs.num * rhs.den == rhs.num * lhs.den;
    }
    friend bool operator!=(const Frac &lhs, const Frac &rhs) {
        return lhs.num * rhs.den != rhs.num * lhs.den;
    }
    friend bool operator<(const Frac &lhs, const Frac &rhs) {
        return lhs.num * rhs.den < rhs.num * lhs.den;
    }
    friend bool operator>(const Frac &lhs, const Frac &rhs) {
        return lhs.num * rhs.den > rhs.num * lhs.den;
    }
    friend bool operator<=(const Frac &lhs, const Frac &rhs) {
        return lhs.num * rhs.den <= rhs.num * lhs.den;
    }
    friend bool operator>=(const Frac &lhs, const Frac &rhs) {
        return lhs.num * rhs.den >= rhs.num * lhs.den;
    }
};

using F = Frac<i64>;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector a(n, std::array<int, 2> {});
    for (auto &[x, y] : a)
        std::cin >> x >> y;

    auto line = [&](int i, int j)
    {
        auto [x1, y1] = a[i];
        auto [x2, y2] = a[j];

        return std::array {y2 - y1, x1 - x2, y1 * x2 - y2 * x1};
    };

    auto norm = [](std::array<int, 3> x)
    {
        auto [a, b, c] = x;
        int g = std::gcd(a, std::gcd(b, c));

        a /= g, b /= g, c /= g;
        if (c < 0)
            a = -a, b = -b, c = -c;

        return std::array {a, b, c};
    };

    std::vector<std::array<int, 3>> l;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
            l.emplace_back(norm(line(i, j)));
    }

    std::sort(std::begin(l), std::end(l));
    l.erase(std::unique(std::begin(l), std::end(l)), std::end(l));

    std::map<F, int> seen;
    i64 ans = 0;
    i64 total = 0;

    for (int i = 0; i < std::size(l); i++)
    {
        auto [a1, b1, c1] = l[i];
        int g = std::gcd(a1, b1);
        a1 /= g, b1 /= g;
        if (b1 == 0)
            a1 = std::abs(a1);
        else if (b1 < 0)
            b1 = -b1, a1 = -a1;

        ans += total - seen[F(a1, b1)];

        // std::cout << a1 << " " << b1 << ":\n";
        // for (auto [f, _] : seen)
        //     std::cout << f.num << " " << f.den << " " << _ << std::endl;
        // std::cout << std::endl;

        total++;
        seen[F(a1, b1)]++;
    }   

    std::cout << ans;

    return 0;
}