#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int l = 7;

struct Cube
{
    int x, y, z;
    Cube(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {}
};

int overlap(std::vector<Cube> cubes)
{
    std::array<int, 3> max{-7, -7, -7}, min{7, 7, 7};

    for (auto &[x, y, z] : cubes)
    {
        max[0] = std::max(max[0], x);
        max[1] = std::max(max[1], y);
        max[2] = std::max(max[2], z);
        min[0] = std::min(min[0], x);
        min[1] = std::min(min[1], y);
        min[2] = std::min(min[2], z);
    }

    int length = std::max(0, min[0] - max[0] + 7);
    int width = std::max(0, min[1] - max[1] + 7);
    int height = std::max(0, min[2] - max[2] + 7);

    return length * width * height;
}

void disp(Cube a, Cube b, Cube c)
{
    for (auto p : {a, b, c})
        std::cout << p.x << " " << p.y << " " << p.z << " ";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::array<int, 3> v{};
    for (int i = 0; i < 3; i++)
        std::cin >> v[i];

    for (int i = -l; i <= l; i++)
    {
        for (int j = -l; j <= l; j++)
        {
            for (int k = -l; k <= l; k++)
            {
                for (int x = -l; x <= l; x++)
                {
                    for (int y = -l; y <= l; y++)
                    {
                        for (int z = -l; z <= l; z++)
                        {
                            Cube first(0, 0, 0);
                            Cube second(i, j, k);
                            Cube third(x, y, z);

                            int v1, v2, v3;
                            v1 = v2 = v3 = l * l * l;
                            int v12 = overlap({first, second});
                            int v13 = overlap({first, third});
                            int v23 = overlap({second, third});
                            int v123 = overlap({first, second, third});
                            v1 = v1 - v12 - v13 + v123;
                            v2 = v2 - v23 - v12 + v123;
                            v3 = v3 - v13 - v23 + v123;

                            if (v1 + v2 + v3 == v[0] and v12 + v13 + v23 - 3 * v123 == v[1] and v123 == v[2])
                            {
                                std::cout << "Yes\n";
                                disp(first, second, third);
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }

    std::cout << "No";


    return 0;
}