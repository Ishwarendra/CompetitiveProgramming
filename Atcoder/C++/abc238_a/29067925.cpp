#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
using vi = vector<int>;
using vll = vector<long long>;
using ll = long long;


ll func(ll n, vll &dp, vi &height)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return abs(height[n] - height[n - 1]);
    if (dp[n] != -1)
        return dp[n];

    return dp[n] = min(func(n - 1, dp, height) + abs(height[n] - height[n - 1]), func(n - 2, dp, height) + abs(height[n] - height[n - 2]));    
} 

void solve()
{
    int n; cin >> n;
    vi h(n + 1);
    vll dp(n + 1, -1);

    for(int i = 1; i <= n; i++)
        cin >> h[i];
    
    cout << func(n, dp, h) << "\n";

}

int main()
{
    // FIO
    int t = 1;
    // cin >> t;
    while(t--)
          solve();
    return 0;
}