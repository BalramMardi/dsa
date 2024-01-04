#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main (){

        int n;
        cin >> n;
      int arr[n];
      for (int i = 0; i < n; i++) {
         cin >> arr[i];
      }

      int omax = 0;
      int dp[n];
      for(int i = 0; i < n; i++){
         int max = 0 ; 

         for(int j = 0; j < i; j++){
            if(arr[j] <= arr[i]){
               if(max == 0 || dp[j] > max){
                  max = dp[j];
               }
            }
         }

         if(max != 0){
            dp[i] = max + 1;
         } else {
            dp[i] = 1;
         }
         
         if(dp[i] > omax){
            omax = dp[i];
         }
      }

      cout << omax;
   }




                        