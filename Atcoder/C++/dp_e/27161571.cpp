#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    string s, t;
    cin >> s >> t;

    int n = s.length(), m = t.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    // Base-Case
    for(int i = 0; i < n; i++)
        dp[i][0] = 0;
    for(int i = 1; i < m; i++)
        dp[0][i] = 0;
    
    string ans;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    int ans_size = dp[n][m];
    int i = n - 1, j = m - 1;
    // cout << ans_size << "\n";
    while (ans.length() < ans_size)
    {
        // cout << ans.length() << " " << ans << "\n";

        if (s[i] == t[j])
            ans += s[i], i--, j--;
        else if (dp[i][j + 1] >= dp[i + 1][j])
            i--;
        else 
            j--;
    }

    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
}

int main()
{
    int t = 1;
    // cin >> t;
    while(t--)
          solve();
    return 0;
}