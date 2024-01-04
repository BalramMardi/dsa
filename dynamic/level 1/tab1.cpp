#include <iostream>
using namespace std;

int cs(int n){
    int dp[n + 1];
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        dp[i] = dp[i - 1];
        if(i >= 2){
            dp[i] += dp[i - 2];
        }
        if(i >= 3){
            dp[i] += dp[i - 3];
        }
    }
    return dp[n];

}

int main(){
    int n;
    cin>>n;
    cout<<cs(n)<<endl;
}
                                