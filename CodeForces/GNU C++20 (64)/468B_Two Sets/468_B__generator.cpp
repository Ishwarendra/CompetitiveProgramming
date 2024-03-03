#include "bits/stdc++.h"

using i64 = long long;

std::seed_seq seed
{
    (uint32_t)std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count(),
    (uint32_t)std::random_device()(),
    (uint32_t)(uintptr_t)std::make_unique<char>().get()
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
    
    int n = 5;
    int a = get_rand(10, 20);
    int b = get_rand(10, 20);
    std::cout << n << " " << a << " " << b << "\n";

    for (int i = 0; i < n; i++)
        std::cout << get_rand(1, 10) << " \n"[i == n - 1];
    
    return 0;
}