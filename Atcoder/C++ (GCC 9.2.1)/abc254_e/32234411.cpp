#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

using i64 = long long;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
}; 

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    i64 n, m;
    std::cin >> n >> m;

    std::vector<int> adj[n + 1];

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        std::cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // std::map<int, std::map<int, i64>> d;

    // for (int i = 1; i <= n; ++i)
    //     d[i][0] = i, d[i][1] = 0, d[i][2] = 0, d[i][3] = 0;

    // std::vector<int> vis(n + 1);
    // std::function<void(int)> bfs;

    // bfs = [&](int u)
    // {
    //     std::queue<int> q;
    //     q.emplace(u);

    //     vis[u] = 1;
    //     int cnt = 0;

    //     while (!q.empty())
    //     {
    //         auto cur = q.front();
    //         q.pop();

    //         for (int nb : adj[cur])
    //         {
    //             if (vis[nb])
    //                 continue;

    //             if (cnt < 3)
    //             {
    //                 d[u][cnt + 1] += nb;
    //                 d[nb][cnt + 1] += u;

    //                 q.push(nb);
    //                 vis[nb] = 1;
    //             }
    //             else
    //                 break;
    //         }

    //         cnt++;
    //     }
    // };

    int q;
    std::cin >> q;

    while (q--)
    {
        int x, k;
        std::cin >> x >> k;

        std::unordered_set<int, custom_hash> s;
        int cnt = 0;
        std::queue<int> q;

        q.push(x);
        s.insert(x);

        while (!q.empty() and cnt < k)
        {
            int sz = q.size();

            for (int i = 0; i < sz; ++i)
            {
                auto cur = q.front();
                q.pop();

                for (int nb : adj[cur])
                {
                    if (!s.count(nb))
                        q.push(nb), s.insert(nb);
                }
            }

            cnt++;
        }

        i64 ans = 0;

        for (int i : s)
            ans += i * 1LL;

        std::cout << ans << "\n";
    }

    return 0;
}