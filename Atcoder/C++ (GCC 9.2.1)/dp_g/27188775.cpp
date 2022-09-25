#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

// Given a directed graph find it's diamater, i.e., longest path
vector<int> graph[100005]; // array of 1005 vectors
int dp[100005];

int longest_path(int src)
{
    if (dp[src] != -1)
        return dp[src];
    
    int max_val = 0;
    bool is_leaf_node = true;

    for(int child : graph[src])
    {
        is_leaf_node = false;
        max_val = max(max_val, longest_path(child));
    }

    return dp[src] = (is_leaf_node ? 0 : 1 + max_val);
}

int main()
{
    memset(dp, -1, sizeof dp);
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }

    int result = -999999;
    for(int i = 1; i <= n; i++)
    {
        result = max(result, longest_path(i));
    }
    cout << result << "\n";

    return 0;
}