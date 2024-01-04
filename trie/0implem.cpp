#include <iostream>

const int ALPHABET_SIZE = 26;

class TrieNode
{
public:
    TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;

    TrieNode()
    {
        for (int i = 0; i < ALPHABET_SIZE; ++i)
        {
            children[i] = nullptr;
        }
        isEndOfWord = false;
    }
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
            int index = ch - 'a';
            if (!current->children[index])
            {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        current->isEndOfWord = true;
    }

    bool search(const std::string &word)
    {
        TrieNode *current = root;
        for (char ch : word)
        {
            int index = ch - 'a';
            if (!current->children[index])
            {
                return false;
            }
            current = current->children[index];
        }
        return current->isEndOfWord;
    }

    bool startsWith(const std::string &prefix)
    {
        TrieNode *current = root;
        for (char ch : prefix)
        {
            int index = ch - 'a';
            if (!current->children[index])
            {
                return false;
            }
            current = current->children[index];
        }
        return true;
    }
};

int main()
{
    Trie trie;

    trie.insert("apple");
    std::cout << "Search 'apple': " << (trie.search("apple") ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 'app': " << (trie.search("app") ? "Found" : "Not Found") << std::endl;
    std::cout << "StartsWith 'app': " << (trie.startsWith("app") ? "Found" : "Not Found") << std::endl;

    return 0;
}
