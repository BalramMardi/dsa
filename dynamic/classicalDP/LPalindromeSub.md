## left right approach

```cpp
class Solution {
private:
public:
    string longestPalindrome(string s) {
        string ans;
        int maxLen = 0;
        int l = 0, r = 0;
        for(int i = 0; i < s.size(); i++) {
            l = i;
            r = i;

            while(l >= 0 && r < s.size()){
                if(s[l] == s[r]){
                    if((r - l + 1) > maxLen) {
                        maxLen = r - l + 1;
                        ans = s.substr(l, maxLen);
                    }
                } else {
                    break;
                }

                l--;
                r++;
            }

            l = i;
            r = i + 1;

            while(l >= 0 && r < s.size()){
                if(s[l] == s[r]){
                    if((r - l + 1) > maxLen) {
                        // cout << "even got " << endl;
                        maxLen = r - l + 1;
                        ans = s.substr(l, maxLen);
                    }
                } else {
                    break;
                }

                l--;
                r++;
            }
        }
        return ans;
    }
};

// get  all substrings


```

## Method 2

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        int resStart=0, resLen = 1;
        if(s.size()==1) return s;
        int si = 0;
        for(int i=0; i<s.size(); i++) {
            si = i;
            while(i+1<s.size() && s[i]==s[i+1]) i++;
            int end = i+1;
            si--;
            while(si>=0 && end<s.size() && s[si]==s[end]) {
                si--;
                end++;
            }
            si++;
            end--;
            if(resLen<end-si+1) {
                resLen = end-si+1;
                resStart = si;
            }
        }

        return s.substr(resStart, resLen);
    }
};

```

## DP approach

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        string len;
        vector<vector<bool>> dp(s.length(), vector<bool>(s.length(),false));
        for(int g=0;g<s.length();g++){
            for(int i=0,j=g ; j<s.length() ; j++,i++){
                if(g==0){
                    dp[i][j]= true;
                }

                else if(g==1){
                    dp[i][j]= s[i]==s[j];
                }

                else
                    dp[i][j]= s[i]==s[j] and dp[i+1][j-1];


                if(dp[i][j] && g + 1 > len.length()){
                    len = s.substr(i, g + 1);
                }
            }
        }

        return len;
    }
};

```
