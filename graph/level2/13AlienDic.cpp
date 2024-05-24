#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

string alienOrder(vector<string> &words)
{
    unordered_map<char, unordered_set<char>> map;
    unordered_map<char, int> degree;
    string result = "";

    if (words.empty())
    {
        return result;
    }

    for (const string &s : words)
    {
        for (char c : s)
        {
            degree[c] = 0;
        }
    }

    // Step 2: Build the graph by comparing adjacent words

    for (int i = 0; i < words.size() - 1; i++)
    {
        bool flag = false;
        string cur = words[i];
        string next = words[i + 1];
        int length = min(cur.length(), next.length());

        for (int j = 0; j < length; j++)
        {
            char c1 = cur[j];
            char c2 = next[j];

            if (c1 != c2)
            {

                unordered_set<char> &set = map[c1];
                if (!set.count(c2))
                {
                    set.insert(c2);
                    degree[c2]++;
                }
                flag = true;
                break;
            }
        }

        if (!flag && next.length() < cur.length())
        {
            return "";
        }
    }

    // Step 3: Perform topological sort using Kahn's Algorithm
    queue<char> q;
    for (const auto &entry : degree)
    {
        if (entry.second == 0)
        {
            q.push(entry.first);
        }
    }

    while (!q.empty())
    {
        char c = q.front();
        q.pop();
        result += c;

        if (map.count(c))
        {
            for (char c2 : map[c])
            {
                degree[c2]--;
                if (degree[c2] == 0)
                {
                    q.push(c2);
                }
            }
        }
    }

    if (result.length() != degree.size())
    {
        return "";
    }

    return result;
}

int main()
{
    int n;
    cin >> n;

    vector<string> words(n);
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }

    cout << alienOrder(words) << endl;

    return 0;
}
