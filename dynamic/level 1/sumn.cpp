#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{

 int count=0;
int arr[3][3] = {{3,5,6},
                  {9,8,7},
                  {2,5,7}};
                  
int n;
cin >> n;
  int sec= 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
 
           
 
           
            if ((i + j) == (n - 1))
                sec += arr[i][j];
        }
    }
 
   
    cout << sec << endl;
}
 
 
