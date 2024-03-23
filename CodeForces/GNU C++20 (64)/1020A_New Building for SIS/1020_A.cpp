#include <iostream>

int main() {
  int n, h, a, b, k;
  std::cin >> n >> h >> a >> b >> k;

  for (int i = 0; i < k; i++) {
    int ta, fa, tb, fb;
    std::cin >> ta >> fa >> tb >> fb;

    if (ta == tb) {
      std::cout << std::abs(fa - fb) << "\n";
    } else {
      int ans = 0;
      if (fa <= a) {
        ans += a - fa, fa = a;
      } else if (fa >= b) {
        ans += fa - b, fa = b;
      }

      ans += std::abs(fa - fb) + std::abs(ta - tb);
      std::cout << ans << "\n";
    }
  }
}
