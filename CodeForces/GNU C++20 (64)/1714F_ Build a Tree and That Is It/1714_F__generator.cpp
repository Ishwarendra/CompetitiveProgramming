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

    int n = 6;
    std::cout << "1\n" << n << "\n";

    while (true)
    {
        std::array<int, 3> a;
        a[0] = 2;
        for (int i = 1; i < 3; i++)
            a[i] = get_rand<int>(1, n - 1);

        auto b = a;
        std::sort(std::begin(b), std::end(b));
        if (b[0] + b[1] == b[2] and a != std::array<int, 3>{2, 3, 3})
            continue;
        else
        {
            std::cout << a[0] << " " << a[1] << " " << a[2] << "\n";
            std::exit(0);
        }
    }
    return 0;
}