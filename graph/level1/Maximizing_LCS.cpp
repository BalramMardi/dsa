#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int lcs( char *X, char *Y, int m, int n ) 
{ 
    if (m == 0 || n == 0) 
        return 0; 
    if (X[m-1] == Y[n-1]) 
        return 1 + lcs(X, Y, m-1, n-1); 
    else
        return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n)); 
} 
int main()
{
 int t;
 cin >> t;
 while (t!=0)
 {
    /* code */
    int n;
    cin >> n;
    int mid = n/2;
    char name[n];
    for (int i = 0; i < n; i++)
    {
        
        cin >> name[i];
    }

    char first[mid];
    char second[mid];
    

    for (int i = 0; i < mid; i++)
    {
        first[i]=name[i];
        
    }
    int j=n-1;
    for (int i = 0; i < mid; i++)
    {
        
        second[i]=name[j];
        j--;
        
    }
    
    int numm =lcs(first,second,mid,mid);
    cout << numm << endl;

    
    

   
    t--;

 }
 }
 
 
 
