#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int n; cin >> n;
    vector<int> a(n), b(n), c(n);

    for(int i = 0; i < n; i++)
        cin >> a[i] >> b[i] >> c[i];
    
    vector<vector<int>> dp(3, vector<int>(n));
    // dp[x][i] -> if on i-th day we do task-x then max happiness we get

    // Base-Case
    dp[0][0] = a[0]; 
    dp[1][0] = b[0];
    dp[2][0] = c[0];

    for(int i = 1; i < n; i++)
    {
        dp[0][i] = a[i] + max(dp[1][i - 1], dp[2][i - 1]);
        dp[1][i] = b[i] + max(dp[0][i - 1], dp[2][i - 1]);
        dp[2][i] = c[i] + max(dp[1][i - 1], dp[0][i - 1]);
    }
    
    cout << max({dp[0][n - 1], dp[1][n - 1], dp[2][n - 1]});
}

int main()
{
    int t = 1;
    // cin >> t;
    while(t--)
          solve();
    return 0;
}