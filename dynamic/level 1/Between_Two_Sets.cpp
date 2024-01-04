#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin >> n >> m ;
    
    int a[n];
    int b[m];
    for (int i = 0; i < n; i++)
    {
        /* code */
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        /* code */
        cin >> b[i];
    }
     int max=a[0];
    for (int i = 1; i < n; i++)
    {
        
        if(a[i]>max)
        max=a[i];
    }
    int min=b[0];
    for (int i = 1; i < m; i++)
    {
       
        if(b[i]<min)
        min=b[i];
    }
    
    for (int i = max; i < min; i++)
    {
        
        
    } 
    int ans=0;
    for(int x=max;x<=min;x++){
        
        for(int i=0;i<n;i++) {
            if(x % a[i]==0) 
            {
                for(int j=0;j<m;j++) 
                   {
                    if(b[j]%x==0) 
                       ans++;
                    }
            }
            }
    }
     cout<<ans<<endl;
}
   

 
 
