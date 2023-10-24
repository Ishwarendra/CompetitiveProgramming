#include<bits/stdc++.h>

using i64 = long long;

std::vector<std::vector<i64>> dp;
std::vector<i64> wt, val;

constexpr i64 inf = 7e18;

i64 f(int i, int w)
{
	if (w < 0)
		return -inf;
	
	if (i == 0)
	{
		if (w - wt[i] >= 0)
			return val[i];
		else
			return 0LL;
	}
	
	if (dp[i][w] != -1)
		return dp[i][w];
	
	dp[i][w] = f(i - 1, w);
	
	if (w - wt[i] >= 0)
		dp[i][w] = std::max(dp[i][w], f(i - 1, w - wt[i]) + val[i]);
	
	return dp[i][w];
}

int main()	
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, w;
	std::cin >> n >> w;
	
	dp.resize(n, std::vector<i64>(w + 1, -1));
	wt.resize(n);
	val.resize(n);
	
	for (int i = 0; i < n; i++)
		std::cin >> wt[i] >> val[i];
	
	std::cout << f(n - 1, w) << '\n';
	
	return 0;
}