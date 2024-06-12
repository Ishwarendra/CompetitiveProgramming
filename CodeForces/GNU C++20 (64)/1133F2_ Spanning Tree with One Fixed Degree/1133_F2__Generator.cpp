#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

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
    
    int n = get_rand(4, 8);
    int max = n * (n - 1) / 2 - n + 1;
    
    std::vector<int> deg(n);
    std::vector<std::pair<int, int>> edges;
    std::set<std::pair<int, int>> done;
    
    for (int i = 1; i < n; i++)
    {
        int v = get_rand(1, i);
        edges.emplace_back(v, i + 1);
        done.emplace(v, i + 1);
        deg[v - 1]++;
        deg[i]++;
    }
    
    for (int i = 0; i < std::min(max, 4); i++)
    {
        int u = 1, v = 1;
        while (u == v or done.count({u, v}))
        {
            u = get_rand(1, n), v = get_rand(1, n);
            if (u > v) 
                std::swap(u, v);
        }
        
        done.emplace(v, u);
        edges.emplace_back(u, v);
    }
    
    std::cout << n << " " << std::size(edges) << " " << get_rand(1, deg[0]) << "\n";
    for (auto [u, v] : edges)
        std::cout << u << " " << v << "\n";
    
    return 0;
}