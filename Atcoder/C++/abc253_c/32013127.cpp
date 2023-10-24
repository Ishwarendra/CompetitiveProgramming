#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

void solve()
{
	int n, m;
	std::cin >> n >> m;

	std::vector<std::string> a(n);

	for (int i = 0; i < n; ++i)
		std::cin >> a[i];

	int x1 = -1, y1 = -1, x2, y2;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (a[i][j] == 'o' and x1 == -1)
				x1 = i, y1 = j;
			else if (a[i][j] == 'o')
				x2 = i, y2 = j;
		}
	}

	std::cout << abs(x2 - x1) + abs(y2 - y1);
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	// std::cin >> t;

	while (t--)
		solve();

	return 0;
}