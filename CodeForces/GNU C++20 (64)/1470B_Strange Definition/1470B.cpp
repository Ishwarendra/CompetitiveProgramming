#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

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

constexpr int N = 1e6 + 1;
std::vector<int> min_prime;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    auto norm = [&](int x)
    {
        int ans = 1;
        while (x > 1)
        {
            int min = min_prime[x];
            int cnt = 0;
            while (x % min == 0)
                x /= min, cnt ^= 1;

            if (cnt)
                ans *= min;
        }

        return ans;
    };

    std::map<int, int> m;

    int zero = 0, one = 0, odd = 0;
    for (int i = 0; i < n; i++)
    {
        int x = norm(a[i]);
        m[x]++;
        zero = std::max(zero, m[x]); 
    }

    for (auto &[num, f] : m)
    {
        if (num == 1 || f % 2 == 0)
            one += f;
        else
            odd = std::max(odd, f);
    }

    int q;
    std::cin >> q;

    while (q--)
    {
        i64 w;
        std::cin >> w;

        std::cout << (w ? std::max(one, odd) : zero) << "\n";
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    min_prime = nt::minPrime(N);

    int t;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}