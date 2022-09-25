#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;

const int mx_size = 1e5 + 5;
vector<vi> adj(mx_size);
vector<int> dp(mx_size, -1);

int longest_path(int src)
{
    if (adj[src].size() == 0)
        return 0;
    
    int max_path = 0;
    for(int nb : adj[src])
    {
        if (dp[nb] != -1)
            max_path = max(max_path, dp[nb]);
        else
            max_path = max(max_path, longest_path(nb));
    }

    return dp[src] = 1 + max_path;
}

int main()
{
    // memset(dp, -1, sizeof dp);
    int n, m;
    cin >> n >> m;

    while(m--)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        if (dp[i] == -1)
            ans = max(ans, longest_path(i));
        else
            ans = max(ans, dp[i]);
    }

    cout << ans << "\n";

    return 0;
}