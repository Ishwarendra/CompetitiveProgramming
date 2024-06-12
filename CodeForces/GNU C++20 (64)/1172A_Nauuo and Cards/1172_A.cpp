#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

/**
 * Upper Bound on answer is 2*n
 * Keep swapping your zero cards with all cards on board until you get all non-zero cards
 * Then you can throw cards in sorted order
 * 
 * Observations:
 *     No need to throw a zero card, just throw numbered card and win game.
 *     If you play even one zero card then you have to start building your answer from 1.
 *     Must pick all numbered card at some point
 *     If you have to start from 1, then answer is calculated:
 *         number of card you need to pick to get card-x in your hand
 *         + n to throw all in sorted order. Max of all cards will be answer.
 *         - cards less than x which is in our hand
 */

constexpr int inf = 1e9;

int get(std::vector<int> a, std::deque<int> b)
{
    int n = std::size(a);
    std::set<int> m;
    int zero = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i])
            m.emplace(a[i]);
        else
            zero++;
    }
    
    int need = b.back();
    int ok = need;
    for (int i = n - 1; i >= 0; i--)
    {
        if (b[i] == ok)
            ok--;
        else
            break;
    }
    
    if (ok > 0)
        need = 1;
    else
        need++;
    

    int ans = 0;
    while (need != n + 1)
    {
        if (m.count(need))
        {
            b.emplace_back(need);
            m.erase(need);
            need++;
        }
        else
            return 2 * n + 1;
        
        if (b.front())
            m.emplace(b.front());
        else
            zero++;
        
        b.pop_front();
        ans++;
        
        if (ans > 2 * n)
            return ans;
    }
    
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    
    std::map<int, int> pos;
    std::vector<int> a(n);
    std::deque<int> b(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        pos[a[i]] = 0;
    }
    
    for (int i = 0; i < n; i++)
    {
        std::cin >> b[i];
        pos[b[i]] = i;
    }
    
    int ans = get(a, b);
    int other = 0;
    
    for (int i = 0; i < n; i++)
        other = std::max(other, pos[i + 1] + 1 - i + n);

    ans = std::min(ans, other);
    std::cout << ans;

    return 0;
}