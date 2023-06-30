#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

struct TrieNode
{
    TrieNode* nxt[2]{};
    bool ended;

    TrieNode() : ended(false) {}
    void put(int x, TrieNode* a) { nxt[x] = a; }
    TrieNode* get(int x) { return nxt[x]; }
    bool contains(int x) { return !!nxt[x]; }
    void setTerminal() { ended = true; }
    void unsetTerminal() { ended = false; }
    bool isTerminal() { return ended; }
    bool isEmpty() 
    {
        if (nxt[0] or nxt[1])
            return false;
        return true;
    }
};

struct Trie
{
private:
    TrieNode* root;
    const int M = 29;
    int getBit(int x, int pos) { return (x >> pos) & 1; }

    TrieNode* remove(int x, TrieNode* node, int depth)
    {
        if (!node)
            return nullptr;

        if (depth == -1)
        {
            if (node->isTerminal())
                node->unsetTerminal();

            if (node->isEmpty())
            {
                delete node;
                node = nullptr;
            }
            return node;
        }

        int bit = getBit(x, depth);
        node->nxt[bit] = remove(x, node->nxt[bit], depth - 1);

        if (node->isEmpty() and !node->isTerminal())
        {
            delete node;
            node = nullptr;
        }

        return node;
    }
public:
    Trie() { root = new TrieNode(); }
    void insert(int x)
    {
        TrieNode* node = root;
        for (int i = M; i >= 0; i--)
        {
            int bit = getBit(x, i);
            if (!node->contains(bit))
                node->put(bit, new TrieNode());
            node = node->get(bit);
        }

        node->setTerminal();
    }
    void remove(int x)
    {
        TrieNode *node = root;
        remove(x, node, M);
    }
    int get(int x)
    {
        int y = 0;
        TrieNode *node = root;
        for (int i = M; i >= 0; i--)
        {
            int need = 1 ^ getBit(x, i);
            assert(!!node == 1);
            if (node->contains(need))
            {
                node = node->get(need);
                if (need)
                    y |= 1 << i;
            }
            else 
            {
                node = node->get(1 - need);
                if (!need)
                    y |= 1 << i;
            }
        }
        
        return (y ^ x);
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int q;
    std::cin >> q;

    std::map<int, int> m;
    Trie trie;
    trie.insert(0);
    while (q--)
    {
        char ch;
        int x;
        std::cin >> ch >> x;

        if (ch == '+')
        {
            m[x]++;
            trie.insert(x);
        }
        else if (ch == '-')
        {
            m[x]--;
            if (m[x] == 0)
                trie.remove(x);
        }
        else
            std::cout << trie.get(x) << "\n";
    }
    
    return 0;
}