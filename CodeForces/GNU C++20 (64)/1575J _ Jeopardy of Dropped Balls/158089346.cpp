#include <bits/stdc++.h>
 
#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif
 
void solve()
{
 int n, m, k;
 std::cin >> n >> m >> k;
 
 std::vector<std::vector<int>> a(n, std::vector<int>(m));
 
 for (int i = 0; i < n; ++i)
  for (int j = 0; j < m; ++j)
   std::cin >> a[i][j];
 
 auto safe = [&](int i, int j)
 {
  return i >= 0 and j >= 0 and i < n and j < m;
 };
 
 while (k--)
 {
  int x = 0, y;
  std::cin >> y;
  y--;
  
  while (safe(x, y))
  {
   if (a[x][y] == 1)
   {
    a[x][y] = 2;
    y += 1;
   }
   else if (a[x][y] == 2)
    x += 1;
   else
   {
    a[x][y] = 2;
    y -= 1;
   }
  }
  
  std::cout << y + 1 << " ";
 }
 
 std::cout << "\n";
}
 
int main()
{
 std::ios::sync_with_stdio(false);
 std::cin.tie(nullptr);
 
 int t = 1;
 // std::cin >> t;
 
 while (t--)
  solve();
 
 return 0;
}