#include<bits/stdc++.h>

using i64 = long long;

constexpr int MAXN = 1e5 + 1;
constexpr i64 inf = 1e18;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, w;
	std::cin >> n >> w;
	
	std::vector<int> wt(n), val(n);
	
	for (int i = 0; i < n; i++)
		std::cin >> wt[i] >> val[i];
	
	std::vector<std::vector<i64>> dp(n + 1, std::vector<i64>(MAXN, inf)); 
	
	dp[0][0] = 0;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < MAXN; j++)
		{
			if (j - val[i] >= 0)
				dp[i + 1][j] = std::min(dp[i][j], dp[i][j - val[i]] + wt[i]);
			else
				dp[i + 1][j] = dp[i][j];
		}
	}
	
	i64 ans = 0;
	
	for (int i = 0; i < MAXN; i++)
		if (w - dp[n][i] >= 0)
			ans = i;
		
	std::cout << ans << "\n";
	
	return 0;
}