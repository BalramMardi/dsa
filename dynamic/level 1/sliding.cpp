#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
 int n, k;
 int arr[n];
 cin >> n >> k;
 int max;

 for (int i = 0; i < n; i++)
 {
    cin >> arr[i];
 }
 
 for (int i = 0; i <= n-k; i++)
 {
    /* code */
    max = arr[i];
      for (int j = 1; j < k; j++)
      {
        /* code */
        if(arr[i+j]>max)
            max=arr[i+j];
      }

      cout << max<< " ";

    
      
 }
 
 
 
}