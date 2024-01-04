#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
 int n;
 cin >> n;
 int coins[n];
 for (int j = 0; j < n; j++)
 {
    cin >> coins[j];
 }
 int amt;
 cin >> amt;
 int dp[amt+1]={};
 dp[0]=1;
 int coinlen = sizeof(coins)/sizeof(int);
 int dplen = sizeof(dp)/sizeof(int);


 for (int i = 0; i < dplen; i++)
 {
    for (int coin:coins)
    {
        if(i>=coin){
            dp[i] += dp[i-coin];
        }
    }
    
 }
 cout << dp[amt];
 


 
}
       