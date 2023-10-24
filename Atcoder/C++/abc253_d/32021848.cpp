#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif
using namespace std;
using i64 = long long;

i64 lcm(i64 a, i64 b)
{
	return (a * b) / __gcd(a, b);
}

void solve()
{
	i64 n, a, b;
	std::cin >> n >> a >> b;

	auto f = [&](i64 x)
	{
		return x * (x + 1LL) / 2;
	};

	i64 sum = f(n);

	i64 numa = n / a, numb = n / b;
	sum -= f(numa) * a;
	sum -= f(numb) * b;
	i64 l = lcm(a, b);

	if (l != 1)
		sum += f(n / l) * l;

	std::cout << std::max(0LL, sum);
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