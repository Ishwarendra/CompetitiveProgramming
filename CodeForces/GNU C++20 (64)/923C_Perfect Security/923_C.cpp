#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

/**
 * For each a[i], find the best p[j] for which (a[i] ^ p[j]) is minimum.
 * Delete p[j] and continue process for other i
 * Trie to optimise above logic
 */

struct TrieNode
{
    std::array<int, 2> cnt{};
    TrieNode* nxt[2]{};
    bool ended;

    TrieNode() : ended(false) 
    {
        cnt.fill(0);
        nxt[0] = nxt[1] = nullptr;
    }
    bool contains(int ch) { return !!nxt[ch]; }
    void put(int ch, TrieNode *a) { nxt[ch] = a; }
    TrieNode* get(int ch) { return nxt[ch]; }
    void setTerminal() { ended = true; }
    bool isTerminal() { return ended; }
    void incrementCount(int ch) { cnt[ch]++; }
    void decrementCount(int ch) { cnt[ch]--; }
    int getCount(int ch) { return cnt[ch]; }
};

struct Trie
{
    TrieNode *root;

    Trie() { root = new TrieNode(); }
    int getBit(int x, int pos) { return x >> pos & 1; }
    void insert(int x)
    {
        TrieNode *node = root;
        for (int i = 29; i >= 0; i--)
        {
            int ch = getBit(x, i);
            if (!node->contains(ch))
                node->put(ch, new TrieNode());
            
            node->incrementCount(ch);
            node = node->get(ch);
        }
        node->setTerminal();
    }
    void remove(int x)
    {
        TrieNode *node = root;
        for (int i = 29; i >= 0; i--)
        {
            int ch = getBit(x, i);
            node->decrementCount(ch);
            node = node->get(ch);
        }
    }
    int getMinXor(int x)
    {
        TrieNode *node = root;
        int res = 0;
        for (int i = 29; i >= 0; i--)
        {
            int ch = getBit(x, i);
            if (node->contains(ch) and node->getCount(ch))
                node = node->get(ch);
            else
            {
                node = node->get(ch ^ 1);
                res |= (1 << i);
            }
        }
        
        return res;
    }
};


int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<int> a(n), p(n);
    
    Trie trie;
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        std::cin >> p[i];
        trie.insert(p[i]);
    }
    
    for (int i = 0; i < n; i++)
    {
        int min = trie.getMinXor(a[i]);
        std::cout << min << " \n"[i == n - 1];
        trie.remove(a[i] ^ min);
    }
    
    return 0;
}