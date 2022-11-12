#include<bits/stdc++.h>
using namespace std;

int mylog2(int x)
{
    int power = 0;
    while ((1LL << power) <= x)
        power++;
    power--;

    return power;
}

int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int h, p;
        cin >> h >> p;

        long long ans = 0;

        int finished = floor(__lg(p)) + 1;
        ans += std::min(finished, h);
        long long rem = 0;
        while (finished < h) {
            rem += (1LL << finished);
            finished++;
        }

        ans += (rem + p - 1) / p;
        std::cout << ans << "\n";
    }
}