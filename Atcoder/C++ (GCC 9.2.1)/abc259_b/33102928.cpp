#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(...) 1;
#define print(...) 1;
#endif

const long double pi = acos(-1);

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cout << std::fixed;
    std::cout << std::setprecision(8); 

    std::cout << std::fixed;
    std::cout << std::setprecision(8); 

    long double x, y, d;
    std::cin >> x >> y >> d;

    d = d * pi / 180;

    long double c = cos(d), s = sin(d);

    long double a = x * c - y * s, b = x * s + y * c;

    std::cout << a << " " << b;

    // auto radian = [&](long double angle)
    // {
    //     return pi * angle / 180.0L;
    // };

    // auto degree = [&](long double angle)
    // {
    //     return 180.0L * angle / pi;
    // };


    // long double theta = 0;

    // if (b != 0)
    //     theta += degree(atan(abs(a) / abs(b)));
    // else
    //     theta += 90.0L;
    // theta += d;

    // long double r = sqrt(a * a + b * b);
    
    // while (theta > 360.0L)
    //     theta -= 360.0L;
    // long double a_dash = sin(radian(theta)) * r, b_dash = r * cos(radian(theta));

    // if (a_dash == -0.0)
    //     a_dash = 0;
    // if (b_dash == -0.0)
    //     b_dash = 0;

    // std::cout << a_dash << " " << b_dash << "\n";

    return 0;
}