// count of longest palindrome substring

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int count(string word)
{

    vector<vector<bool>> dp(false, vector<bool>(word.size()));

    for (int g = 0; g < word.length(); g++)
    {
        for (int i = 0, j = g; j < word.length(); i++, j++)
        {
            if (g == 0)
            {
                dp[i][j] = true;
            }
            else if (g == 1)
            {
                dp[i][j] = word[i] == word[j];
            }
            else
            {

                dp[i][j] = word[i] == word[j] and dp[i + 1][j - 1] == true;
            }
        }
    }
}

int main()
{

    string word = "name";
    int ans = count(word);
}