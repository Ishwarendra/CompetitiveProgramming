#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(x...) 1;
#define pri64(x...) 1;
#endif

using i64 = long long;

void solve()
{
	i64 q;
	std::cin >> q;

	std::map<i64, i64> m;

	while (q--)
	{
		i64 t;
		std::cin >> t;

		if (t == 1)
		{
			i64 x;
			std::cin >> x;
			m[x]++;
		}
		else if (t == 2)
		{
			i64 x, c;
			std::cin >> x >> c;

			if (m[x] <= c)
				m.erase(x);
			else
				m[x] -= c;
		}
		else
		{
			auto max = (--m.end());
			auto min = m.begin();

			std::cout << max->first - min->first << "\n";
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	i64 t = 1;
	// std::cin >> t;

	while (t--)
		solve();

	return 0;
}