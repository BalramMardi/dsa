#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int red[n];
    int blue[n];
    int green[n];

    for (int i = 0; i < n; i++)
    {
        /* code */
        cin >> red[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        /* code */
        cin >> blue[i];
    }
    for (int i = 0; i < n; i++)
    {
        /* code */
        cin >> green[i];
    }
    
 int ored,oblue,ogreen;
 ored=red[0];

 oblue=blue[0];
 ogreen=green[0];


 for (int i =1 ; i < n; i++)
 {
    
    int nred,ngreen,nblue;
    nred= min(oblue,ogreen) + red[i];
    nblue= min(ored,ogreen) + blue[i];
    ngreen= min(oblue,ored) + green[i];

    ored = nred;
    oblue = nblue;
    ogreen=ngreen;
    
 }

 int woot = min(ored,oblue);
 int woo = min(ogreen,woot);

 
 cout << woo;
 
 
}