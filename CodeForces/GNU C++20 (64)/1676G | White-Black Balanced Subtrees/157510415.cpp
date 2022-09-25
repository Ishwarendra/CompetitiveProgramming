#include <bits/stdc++.h>
 
#ifdef LOCAL
 #include <F:\CPP\Debug\debug.h> 
#else
 #define trace(x...) 1;
 #define print(x...) 1;
#endif
 
void solve()
{
 int n;
 std::cin >> n;
 
 std::vector<int> p(n, 1);
 
 for (int i = 1; i < n; i++)
 {
  std::cin >> p[i];
  p[i]--;
 }
  
 std::vector<int> dp(n);
 
 for (int i = 0; i < n; ++i)
 {
  char ch;
  std::cin >> ch;
  
  dp[i] = (ch == 'B' ? 1 : -1);
 }
 
 for (int i = n - 1; i > 0; i--) 
  dp[p[i]] += dp[i];
   
 std::cout << std::count(dp.begin(), dp.end(), 0) << "\n";
}
 
int main()
{
 std::ios::sync_with_stdio(false);
 std::cin.tie(nullptr);
 
 int t = 1;
 std::cin >> t;
 
 while(t--)
  solve();
 
 return 0;
}