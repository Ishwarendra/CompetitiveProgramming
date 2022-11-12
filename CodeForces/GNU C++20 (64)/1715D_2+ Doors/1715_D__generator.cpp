#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

std::seed_seq seed
{
    (uint32_t)std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count(),
    (uint32_t)std::random_device()(),
    (uint32_t)(uintptr_t)std::make_unique<char>().get(),
    (uint32_t)__builtin_ia32_rdtsc()
};
std::mt19937 rng(seed);

template<class T = int> 
T get_rand(T l, T r) 
{
    assert(l <= r);
    return std::uniform_int_distribution<T>(l, r)(rng);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
        
    int n = 3, q = 3;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        a[i] = get_rand(0, 7);


    std::cout << n << " " << q << "\n";
    while (q--)
    {
        int i = get_rand(0, n - 1), j = get_rand(0, n - 1);
        std::cout << i + 1 << " " << j + 1 << " " << (a[i] | a[j]) << "\n";
    }
    
    return 0;
}