#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
 int n;
 cin >> n;
 int arr[n];
 for (int i = 0; i < n; i++)
 {
    /* code */
    cin >> arr[i];
 }
 int oldinc,oldexc;
 oldinc = arr[0];
 oldexc = 0;

 for (int i = 1; i < n; i++)
 {
    /* code */
   int newinc = oldexc + arr[i];
   int newexc = max(oldinc , oldexc);

    oldexc = newexc;
    oldinc = newinc;
 }

 cout << max(oldexc,oldinc);
 
 
 
}