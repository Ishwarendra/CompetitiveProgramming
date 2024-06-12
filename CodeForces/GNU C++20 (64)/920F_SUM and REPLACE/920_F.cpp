#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

/**
 * Every time a_i is replaced with d(a_i) it changes to root(n)
 * Except for 1 and 2 (ignore these indices when doing the replace operation)
 * T(n) = T( root(n) ) + O(1) can be reduced to
 * T(m) = T(m / 2) + O(1) [n = 2^m]
 * log(m) => log(root(n)) = log(n)
 * Thus a number should change atmost log(n) times only
 */

namespace nt
{
std::vector<bool> sieve(const int n)
{
    std::vector<bool> is_prime(n, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < n; i++)
    {
        for (int j = i * i; j < n; j += i)
            is_prime[j] = false;
    }

    return is_prime;
}

std::vector<int> linearSieve(const int n)
{
    std::vector<bool> is_prime(n, true);
    is_prime[0] = is_prime[1] = false;

    std::vector<int> prime;

    for (int i = 2; i < n; i++)
    {
        if (is_prime[i])
            prime.emplace_back(i);

        for (int j = 0; j < std::size(prime) and i * prime[j] < n; j++)
        {
            is_prime[i * prime[j]] = false;
            if (i % prime[j] == 0)
                break;

        }
    }

    return prime;
}

std::vector<int> minPrime(const int n)
{
    std::vector<int> min_prime(n);
    std::iota(std::begin(min_prime), std::end(min_prime), 0);

    for (int i = 2; i * i < n; i++)
    {
        if (min_prime[i] != i)
            continue;
        for (int j = i * i; j < n; j += i)
            min_prime[j] = std::min(min_prime[j], i);
    }

    return min_prime;
}

std::vector<int> phiUptoN(const int n)
{
    std::vector<int> phi(n), prime;
    phi[1] = 1;

    std::vector<bool> is_prime(n, true);

    for (int i = 2; i < n; i++)
    {
        if (is_prime[i])
        {
            phi[i] = i - 1;
            prime.emplace_back(i);
        }

        for (int j = 0; j < std::size(prime) and 1LL * i * prime[j] < n; j++)
        {
            is_prime[i * prime[j]] = false;

            if (i % prime[j])
                phi[i * prime[j]] = phi[i] * phi[prime[j]];
            else
            {
                phi[i * prime[j]] = prime[j] * phi[i];
                break;
            }
        }
    }

    return phi;
}

template<class T>
T phi(T x)
{
    assert(x > 0);
    T res = 1;
    for (T i = 2; i * i <= x; i++)
    {
        if (x % i)
            continue;

        T cur = 1;
        while (x % i == 0)
            x /= i, cur *= i;
        res *= (cur - cur / i);
    }

    if (x > 1)
        res *= (x - 1);
    return res;
}
};

template<class Info,
         class Merge = std::plus<Info>>
struct SegmentTree
{
    const int n;
    const Merge merge;
    std::vector<Info> info;
    SegmentTree(int n = 0) : n(n), merge(Merge()), info(4 << std::__lg(n)) {}

    template <typename T>
    SegmentTree(const std::vector<T> a) : SegmentTree(std::size(a))
    {
        std::function<void(int, int, int)> build;
        build = [&](int l, int r, int id)
        {
            if (l > r)
                return;
            if (l == r)
            {
                info[id] = Info(a[l], l);
                return;
            }

            int m = (l + r) >> 1;
            build(l, m, id * 2 + 1);
            build(m + 1, r, id * 2 + 2);
            pull(id);
        };
        build(0, n - 1, 0);
    }
    void pull(int id)
    {
        info[id] = merge(info[id * 2 + 1], info[id * 2 + 2]);
    }
    void update(int id, int l, int r, int x, const Info &v)
    {
        if (l > r)
            return;
        if (l == r)
        {
            info[id] = v;
            return;
        }

        int m = (l + r) >> 1;
        if (x <= m)
            update(2 * id + 1, l, m, x, v);
        else
            update(2 * id + 2, m + 1, r, x, v);
        pull(id);
    }
    void update(int x, const Info &v)
    {
        update(0, 0, n - 1, x, v);
    }
    Info get(int id, int l, int r, int a, int b)
    {
        if (r < a or l > b)
            return Info();
        if (l >= a and r <= b)
            return info[id];

        int m = (l + r) >> 1;
        return merge(get(2 * id + 1, l, m, a, b), get(2 * id + 2, m + 1, r, a, b));
    }
    Info get(int l, int r)
    {
        return get(0, 0, n - 1, l, r);
    };

    template <class F>
    int findFirst(int id, int l, int r, int a, int b, F pred)
    {
        if (r < a or l > b or !pred(info[id]))
            return -1;

        if (l == r)
            return l;

        int m = (l + r) >> 1;
        int res = findFirst(2 * id + 1, l, m, a, b, pred);
        if (res == -1)
            res = findFirst(2 * id + 2, m + 1, r, a, b, pred);

        return res;
    }

    template <class F>
    int findFirst(int l, int r, F pred) { return findFirst(0, 0, n - 1, l, r, pred); }

    template <class F>
    int findLast(int id, int l, int r, int a, int b, F pred)
    {
        if (r < a or l > b or !pred(info[id]))
            return -1;

        if (l == r)
            return l;

        int m = (l + r) >> 1;
        int res = findLast(2 * id + 2, m + 1, r, a, b, pred);

        if (res == -1)
            res = findLast(2 * id + 1, l, m, a, b, pred);

        return res;
    }

    template <class F>
    int findLast(int l, int r, F pred) { return findLast(0, 0, n - 1, l, r, pred); }
};

struct Info
{
    i64 x;
    Info(i64 x = 0) : x(x) {}
};

Info operator+(const Info &a, const Info &b)
{
    return Info(a.x + b.x);
}

constexpr int N = 1e6 + 1;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto min_prime = nt::minPrime(N);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    SegmentTree<Info> st(n);
    for (int i = 0; i < n; i++)
        st.update(i, Info(a[i]));

    auto divisors = [&](int x)
    {
        int ans = 1;
        while (x > 1)
        {
            int min = min_prime[x];
            int cnt = 0;
            while (x % min == 0)
                cnt++, x /= min;

            ans *= (cnt + 1);
        }

        return ans;
    };

    std::set<int> s;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 2)
            s.emplace(i);
    }

    while (m--)
    {
        int t, l, r;
        std::cin >> t >> l >> r;
        l--, r--;

        if (t == 1)
        {
            auto beg = s.lower_bound(l);
            auto end = s.upper_bound(r);
            std::vector<int> del;

            for (auto it = beg; it != end; it++)
            {
                auto i = *it;
                a[i] = divisors(a[i]);
                if (a[i] <= 2)
                    del.emplace_back(i);

                st.update(i, a[i]);
            }

            for (auto x : del)
                s.erase(x);
        }
        else
            std::cout << st.get(l, r).x << "\n";
    }

    return 0;
}