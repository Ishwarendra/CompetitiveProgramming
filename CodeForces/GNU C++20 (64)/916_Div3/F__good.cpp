#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 222222;
 
int n;
int sz[N];
vector<int> g[N];
 
void init(int v) {
  sz[v] = 1;
  for (int u : g[v]) {
    init(u);
    sz[v] += sz[u];
  }
}
 
int calc(int v, int k) {
  int tot = 0, mx = -1;
  for (int u : g[v]) {
    tot += sz[u];
    if (mx == -1 || sz[mx] < sz[u]) mx = u;
  }
  if (tot == 0) return 0;
  if (sz[mx] - k <= tot - sz[mx])
    return (tot - k) / 2;
  int add = tot - sz[mx];
  return add + calc(mx, max(0, k + add - 1));
}
 
int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; ++i) g[i].clear();
    for (int i = 1; i < n; ++i) {
      int p; cin >> p;
      g[p - 1].push_back(i);
    }
    init(0);
    cout << calc(0, 0) << '\n';
  }
}