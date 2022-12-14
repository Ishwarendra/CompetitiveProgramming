#include <bits/stdc++.h>
 
#ifdef LOCAL
 #include <F:\CPP\Debug\debug.h> 
#else
 #define trace(x...) 1;
 #define print(x...) 1;
#endif
 
using i64 = long long;
 
void solve()
{
 int n;
 std::cin >> n;
 
 std::vector<int> p(n);
 
 for (int i = 0; i < n; ++i) 
 {
  std::cin >> p[i];
  p[i]--;
 }
 
 std::vector<int> cnt(n);
 i64 ans = 0;
 
 // p[c] > p[a] and p[b] > p[d]
 for (int b = 0; b < n; b++)
 {
  int d = 0;
  
  for (int c = n - 1; c > b; c--)
  {
   ans += 1LL * cnt[c] * d;
   d += p[c] < p[b]; 
   cnt[c] += p[b] < p[c];
  }
 }
 
 std::cout << ans << "\n";
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