#include<bits/stdc++.h>

using i64 = long long;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	i64 n, w;
	std::cin >> n >> w;
	
	std::vector<i64> wt(n), val(n);
	std::vector<std::vector<i64>> dp(2, std::vector<i64>(w + 1));
	
	for (int i = 0; i < n; i++)
		std::cin >> wt[i] >> val[i];
	
	for (int i = 0; i <= w; i++)
	{
		if (i - wt[0] >= 0)
			dp[0][i] = val[0];
	}
	
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= w; j++)
		{
			dp[1][j] = dp[0][j];
			
			if (j - wt[i] >= 0)
				dp[1][j] = std::max(dp[1][j], dp[0][j - wt[i]] + val[i]);	
		}
		
		std::swap(dp[0], dp[1]);
	}
	
	std::cout << dp[0][w] << "\n";
	
	return 0;
}