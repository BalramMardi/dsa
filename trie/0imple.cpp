#include <iostream>

using namespace std;

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

void insert(TrieNode *root, const string &word)
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

bool search(TrieNode *root, const string &word)
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

bool startsWith(TrieNode *root, const string &prefix)
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

int main()
{
    TrieNode *root = new TrieNode();

    insert(root, "apple");
    insert(root, "apps");

    cout << "Search 'apple': " << (search(root, "apple") ? "Found" : "Not Found") << endl;
    cout << "Search 'app': " << (search(root, "app") ? "Found" : "Not Found") << endl;
    cout << "Search 'apps': " << (search(root, "apps") ? "Found" : "Not Found") << endl;
    cout << "StartsWith 'app': " << (startsWith(root, "app") ? "Found" : "Not Found") << endl;

    // Clean up memory (optional)
    delete root;

    return 0;
}
