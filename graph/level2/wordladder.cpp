#include <unordered_set>
#include <queue>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> set(wordList.begin(), wordList.end());
        if (set.find(endWord) == set.end())
            return 0;

        queue<string> queue;
        queue.push(beginWord);

        unordered_set<string> visited;
        visited.insert(beginWord);

        int changes = 1;

        while (!queue.empty())
        {
            int size = queue.size();
            for (int i = 0; i < size; ++i)
            {
                string word = queue.front();
                queue.pop();
                if (word == endWord)
                    return changes;

                for (int j = 0; j < word.length(); ++j)
                {
                    string temp = word;
                    for (char k = 'a'; k <= 'z'; ++k)
                    {
                        temp[j] = k;

                        if (set.find(temp) != set.end() && visited.find(temp) == visited.end())
                        {
                            queue.push(temp);
                            visited.insert(temp);
                        }
                    }
                }
            }
            ++changes;
        }
        return 0;
    }
};
