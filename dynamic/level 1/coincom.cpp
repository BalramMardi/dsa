
#include <iostream>

using namespace std;
int main()
{
    int n,amt;
    cin >>n;
    int coins[n];
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
        }
        
    
    cin >> amt;
    int summ=amt;
    int dp[amt+1]={};

    int length= sizeof(dp)/sizeof(int);
    int coinlen =sizeof(coins)/sizeof(int);
    //memset(dp, 0, sizeof(dp));
    dp[0]=1;
    for(int jo = 0; jo < coinlen; jo++){
            for(int j = coins[jo]; j < length; j++){
                
                    dp[j] += dp[j - coins[jo]];
                
            }
        }
        cout << dp[summ] <<endl;

}