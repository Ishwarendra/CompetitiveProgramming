#include <bits/stdc++.h>
#include <assert.h>
 
std::vector<std::vector<int>> adj;
std::vector<std::vector<int>> odd_cyc;
std::vector<std::vector<int>> even_cyc; // uh oh no Need pop_front 
 
void print(std::vector<int> &a)
{
    for(int i : a)
        std::cout << i << " ";
    std::cout << "\n";
}
 
bool power_of_two(int x)
{
    if (x == 0)
        return true;
    
    return (x & (x - 1)) == 0;
}
 
void dfs(int cur, std::vector<bool> &vis, std::vector<int> &path)
{
    vis[cur] = true;
    path.push_back(cur);
 
    for (int nb : adj[cur])
    {
        if (not vis[nb])
            dfs(nb, vis, path);
    }
}
 
int modulo(int a, int mod)
{
    if (a < 0)
        a += mod;
    
    return a % mod;
}
 
std::vector<int> merge(std::vector<int> &a, std::vector<int> &b)
{
    assert(a.size() == b.size());
    
    int n = a.size();
    
    std::vector<int> merged(2 * n);
    
    int a_ptr = 0, b_ptr = 0;
    
    for(int i = 0; i < 2 * n; i++)
    {
        if (a_ptr <= b_ptr)
            merged[i] = a[a_ptr++];
        else
            merged[i] = b[b_ptr++];
    }
    
    return merged;
}
 
int main()
{
    int n;
    std::cin >> n;
 
    adj.resize(n + 1);
 
    for (int i = 1; i <= n; i++)
    {
        int x;
        std::cin >> x;
 
        adj[i].push_back(x);
    }
 
    // Key Property: Any Permutation of n is a set of disjoint cycles
 
    // Linked List convention
 
    // p -> p^2: If odd cycle then just do p[i] = p[i]->next->next;
    // p^2 -> p: If odd cycle then just reverse edges then do p^2[i] = p^2[i]->next->next
    // i.e. p^2[i] = p^2[i]->prev->prev
 
    // p -> p^2: If even length cycle then just break it into two cycles keeping alternates nodes in one cycle
    // p^2 -> p: Merge two cycles (1 -> 1' -> 2 -> 2') where i and i' are in diff cycles.
 
    std::vector<bool> vis(n + 1);
    std::vector<int> ans(n + 1);
 
    for (int i = 1; i <= n; i++)
    {
        std::vector<int> path;
        if (not vis[i])
        {
            dfs(i, vis, path);
            
            if (path.size() % 2 == 0)
                even_cyc.push_back(path);
            else
            {
                int sz = path.size();
                
                std::vector<int> tmp(sz);
                
                // 1 -> 2 -> 3 -> 4 -> 5
                // 1(empty) -> (empty)(4) -> 2(empty) -> (empty)(5) -> 3 
                for(int j = 0, pos = 0; j < 2 * sz; j += 2, pos++)
                    tmp[j % sz] = path[pos];
                
                for(int i = 0; i < sz; i++)
                    ans[tmp[i]] = tmp[modulo(i + 1, sz)];
            }
        }
    }
    
    std::sort(even_cyc.begin(), even_cyc.end(), [&](const std::vector<int> &a, const std::vector<int> &b)
    {
        return a.size() < b.size();
    });
    
    std::vector<std::vector<int>> merged_even_cyc;
    
    // If even cycles of some length are odd in number then there is no way we can merge
    for(int i = 0; i < even_cyc.size(); i += 2)
    {
        if (i + 1 >= even_cyc.size() or even_cyc[i].size() != even_cyc[i + 1].size())
        {
            std::cout << "-1\n";
            return 0;
        }
        
        // Ok deque useless try pushing them in new vector instead
        std::vector<int> first = even_cyc[i],
                         second = even_cyc[i + 1];
                         
        std::vector<int> merged_vec = merge(first, second);
        
        merged_even_cyc.push_back(merged_vec);
    }
        
    for(auto &even : merged_even_cyc)
    {
        int sz = even.size();
        
        for(int i = 0; i < sz; i++)
            ans[even[i]] = even[modulo(i + 1, sz)];
    }
    
    for(int i = 1; i <= n; i++)
    {
        // std::cout << ans[i] << " -> " << ans[ans[i]] << "\n";
        std::cout << ans[i] << " \n"[i == n];
    }
    
    return 0;
}