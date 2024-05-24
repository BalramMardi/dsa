#include <iostream>
#include <unordered_map>
#include <string>

class TrieNode
{
public:
    std::unordered_map<char, TrieNode *> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(const std::string &word)
    {
        TrieNode *current = root;
        for (char ch : word)
        {
            if (current->children.find(ch) == current->children.end())
            {
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
        }
        current->isEndOfWord = true;
    }

    bool search(const std::string &word) const
    {
        TrieNode *current = root;
        for (char ch : word)
        {
            if (current->children.find(ch) == current->children.end())
            {
                return false;
            }
            current = current->children[ch];
        }
        return current->isEndOfWord;
    }

    bool startsWith(const std::string &prefix) const
    {
        TrieNode *current = root;
        for (char ch : prefix)
        {
            if (current->children.find(ch) == current->children.end())
            {
                return false;
            }
            current = current->children[ch];
        }
        return true;
    }

    ~Trie()
    {
        deleteTrie(root);
    }

private:
    void deleteTrie(TrieNode *node)
    {
        for (auto &pair : node->children)
        {
            deleteTrie(pair.second);
        }
        delete node;
    }
};

int main()
{
    Trie trie;
    trie.insert("hello");
    trie.insert("world");

    std::cout << std::boolalpha;
    std::cout << "Search 'hello': " << trie.search("hello") << std::endl;
    std::cout << "Search 'hell': " << trie.search("hell") << std::endl;
    std::cout << "Starts with 'hell': " << trie.startsWith("hell") << std::endl;
    std::cout << "Starts with 'worlds': " << trie.startsWith("worlds") << std::endl;

    return 0;
}
