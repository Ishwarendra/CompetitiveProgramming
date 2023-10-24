#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

void solve()
{
	std::vector<int> a(3);


	for (int i = 0; i < 3; ++i)
		std::cin >> a[i];
	int b = a[1];

	std::sort(a.begin(), a.end());

	if (a[1] == b)
		std::cout << "Yes";
	else
		std::cout << "No";
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