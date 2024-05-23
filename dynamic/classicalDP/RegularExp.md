```cpp
class Solution {
public:
    bool isMatch(string s, string p) {

        int slen = s.length();
        int plen = p.length();
        vector<vector<bool>> dp(plen + 1, vector<bool>(slen + 1, false));
        for (int i = 0; i <= plen; i++) {
            for (int j = 0; j <= slen; j++) {
                if (i == 0 and j == 0) {
                    dp[i][j] = true;
                } else if (i == 0) {
                    dp[i][j] = false;
                } else if (j == 0) {
                    if (p[i - 1] == '*') {
                        dp[i][j] = dp[i - 2][j];
                    } else {
                        dp[i][j] = false;
                    }
                } else {
                    if (p[i - 1] == '*') {
                        dp[i][j] = dp[i - 2][j];

                        if (i >= 2 &&
                            (p[i - 2] == s[j - 1] || p[i - 2] == '.')) {
                            dp[i][j] = dp[i][j] || dp[i][j - 1];
                        }
                    } else if (p[i - 1] == s[j - 1] or p[i - 1] == '.') {
                        dp[i][j] = dp[i - 1][j - 1];
                    } else {
                        dp[i][j] = false;
                    }
                }
            }
        }
        return dp[plen][slen];
    }
};

```