#include <bits/stdc++.h>
 
int main()
{
    int r; std::cin >> r;
    
    std::vector<int> rating {1200, 1400, 1600, 1900, 2100, 2300, 2400, 2600, 3000};
    
    std::cout << *std::upper_bound(rating.begin(), rating.end(), r) << "\n";
}