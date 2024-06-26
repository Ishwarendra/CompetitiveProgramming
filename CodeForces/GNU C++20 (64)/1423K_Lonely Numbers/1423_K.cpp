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


/**
 * Prime numbers are lonely if p^2 DNE
 * Composite numbers are lonely?
 *     X = a * b (Let a > b) { a * a is definitely not lonely }
 *     a = b + s
 *     Are (a, X) friends?
 *     (1, b, a = gcd)
 *     1 + b > a (is it true? only if s >= 2)
 *     1 + a > b (is it true? YES)
 *     a + b > 1 (is it true? YES)
 * 
 * X = a * (a - 1)
 * He is friends with Y = (a - 1) * (a - 1)
 * 
 * (X, Y) friends?
 * (a, a - 1, a - 1) :ok:
 * This construction can be used for any composite number
 */

constexpr int N = 1e6 + 1;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    
    auto prime = nt::linearSieve(N);
    
    while (t--)
    {
        int n;
        std::cin >> n;
        
        int x = std::sqrt(n);
        
        if (x * x < n)
            x++;
        if (x * x > n)
            x--;
        
        auto st = std::upper_bound(std::begin(prime), std::end(prime), x) - std::begin(prime);
        auto en = std::upper_bound(std::begin(prime), std::end(prime), n) - std::begin(prime);
        std::cout << en - st + 1 << "\n";
    }
    
    return 0;
}