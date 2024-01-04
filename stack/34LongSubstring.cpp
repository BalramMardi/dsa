// Longest substring without repition

#include <iostream>
#include <string>
using namespace std;

int longestUniqueSubsttr(string str)
{
    // if string length is 0
    if (str.length() == 0)
        return 0;

    // if string length 1
    if (str.length() == 1)
        return 1;

    // if string length is more than 2
    int maxLength = 0;
    bool visited[256] = {false};

    // left and right pointer of sliding window
    int left = 0, right = 0;
    for (; right < str.length(); right++)
    {

        // if character is not visited then mark visited
        if (visited[str[right]] == false)
            visited[str[right]] = true;

        // if character is visited
        else
        {
            /* capture the unique string from [left ,
            right). Not including right since repeating
            character is at index right.
            */
            maxLength = max(maxLength, (right - left));

            /* Mark all characters until repeating
                character as unvisited but not the repeating
                character as it is in the new unique string.
                However move window past the repeating
                character.
            */
            while (left < right)
            {
                if (str[left] != str[right])
                    visited[str[left]] = false;
                else
                {
                    left++;
                    break;
                }
                left++;
            }
        }
    }

    // compare current left,right with previous result
    maxLength = max(maxLength, (right - left));

    return maxLength;
}

int main()
{
    string s = "GeeksForGeeks!";

    cout << longestUniqueSubsttr(s) << endl;

    // expected result : 7
    // unique substring = eksForG

    return 0;
}
