#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

/**
 * Game ends when max pile becomes 0
 * If starting prefix is 1, 2, 3, .. then player don't have any choice
 * Else current player can always make other work as he/she wants
 * exception: If no number is left current player can't do anything
 */

void solve()
{
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];
    
    std::sort(std::begin(a), std::end(a));
    a.erase(std::unique(std::begin(a), std::end(a)), std::end(a));
    n = std::size(a);
    
    if (n == 1)
    {
        std::cout << "Alice\n";
        return;
    }
    
    int turn = 0;
    while (turn < n and a[turn] == turn + 1)
        turn++;
    
    if (turn == n)
        turn++;
    
    std::cout << (turn % 2 ? "Bob\n" : "Alice\n");
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}