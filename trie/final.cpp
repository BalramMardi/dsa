#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
    bool isEndOfWord = false;
    string fullword = NULL;
};

void insert(TrieNode *root, const string &word)
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
    current->fullword = word;
}

bool search(TrieNode *root, const string &word)
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

bool startsWith(TrieNode *root, const string &prefix)
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

void deleteTrie(TrieNode *node)
{
    for (auto &pair : node->children)
    {
        deleteTrie(pair.second);
    }
    delete node;
}

int main()
{
    TrieNode *root = new TrieNode();

    insert(root, "apple");
    insert(root, "apps");

    cout << "Search 'apple': " << (search(root, "apple") ? "Found" : "Not Found") << endl;
    cout << "Search 'app': " << (search(root, "app") ? "Found" : "Not Found") << endl;
    cout << "Search 'apps': " << (search(root, "apps") ? "Found" : "Not Found") << endl;
    cout << "StartsWith 'app': " << (startsWith(root, "app") ? "Found" : "Not Found") << endl;

    // Clean up memory
    deleteTrie(root);

    return 0;
}
