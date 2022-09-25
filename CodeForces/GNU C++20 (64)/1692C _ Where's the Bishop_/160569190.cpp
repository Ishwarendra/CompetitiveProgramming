#include <bits/stdc++.h>
 
#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif
 
void solve()
{
    int n = 8, m = 8;
    std::vector<std::string> grid(8);
    for (int i = 0; i < 8; ++i)  
        std::cin >> grid[i];
 
    auto check = [&](int x, int y)
    {
        int i = x, j = y;
 
        while (i < n and j < n)
        {
            if (grid[i][j] == '.')
                return false;
 
            i++, j++;
        }
 
        i = x, j = y;
        while (i >= 0 and j < n)
        {
            if (grid[i][j] == '.')
                return false;
 
            i--, j++;
        }
 
        i = x, j = y;
        while (j >= 0 and i < n)
        {
            if (grid[i][j] == '.')
                return false;
 
            j--, i++;
        }
 
        i = x, j = y;
        while (i >= 0 and j >= 0)
        {
            if (grid[i][j] == '.')
                return false;
 
            i--, j--;
        }
 
        return true;
    };
 
    for (int i = 1; i < 7; i++)
    {
        for (int j = 1; j < 7; j++)
        {
            if (grid[i][j] == '#' and check(i, j))
            {
                std::cout << i + 1 << " " << j + 1 << "\n";
                return;
            }
        }
    }
}
 
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}