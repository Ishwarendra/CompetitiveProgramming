#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int N = 20;

struct TrieNode
{
    TrieNode* link[2];
    bool end;

    TrieNode() 
    {
        for (int i = 0; i < 2; i++)
            link[i] = nullptr;
        end = false;
    }

    bool isTerminal() { return end; }
    void setTerminal() { end = true; }
    TrieNode* get(int bit) { return link[bit]; }
    void put(int bit, TrieNode *t) { link[bit] = t; }
    bool contains(int bit) { return !!link[bit]; }
};

struct Trie
{
    TrieNode *root;
    Trie() { root = new TrieNode(); }
    int getBit(int x, int pos) { return x >> pos & 1; }
    void insert(int x)
    {
        auto node = root;
        for (int i = N - 1; i >= 0; i--)
        {
            auto bit = getBit(x, i);
            if (!node->contains(bit))
                node->put(bit, new TrieNode());

            node = node->get(bit);
        }

        node->setTerminal();
    }

    int getMax(int x)
    {
        auto node = root;
        int max = 0;
        for (int i = N - 1; i >= 0; i--)
        {
            auto bit = getBit(x, i);
            if (node->contains(1 - bit))
            {
                max |= (1 << i);
                node = node->get(1 - bit);
            }
            else
                node = node->get(bit);
        }

        return max;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    auto trie = Trie();
    trie.insert(0);
    std::vector<int> p(n);
    for (int i = 0; i < n - 1; i++)
    {
        int x;
        std::cin >> x;
        p[i + 1] = p[i] ^ x;
        trie.insert(p[i + 1]);
    }

    for (int st = 0; st < n; st++)
    {
        if (trie.getMax(st) >= n)
            continue;

        for (int i = 0; i < n; i++)
            std::cout << (p[i] ^ st) << " \n"[i == n - 1];
        return 0;
    }

    return 0;
}