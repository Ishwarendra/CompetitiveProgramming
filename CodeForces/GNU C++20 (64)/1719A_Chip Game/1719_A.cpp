#include <iostream>

void solve() {
  int n, m;
  std::cin >> n >> m;

  std::cout << ((n + m) % 2 ? "Burenka\n" : "Tonya\n");
}

int main() {
  int t;
  std::cin >> t;

  while (t--) {
    solve();
  }
}
