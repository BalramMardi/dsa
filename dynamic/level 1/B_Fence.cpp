#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
 int n,k;
 cin >> n>>k;
 int arr[n];

 for (int i = 0; i < n; i++)
 {
    cin >> arr[i];
 }
    int min=INT_MAX;
    int sum=0;
    int index=0;
 for (int i = 1; i <=(n-1); i++)
 {
    /* code */

    int sum = arr[i-1]+arr[i]+arr[i+1];

    if(sum < min){
        min=sum;
        index = i;
    }
 }
 cout << index;
 
 
 
}