#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
 int t;
 cin >> t;
 while (t!=0)
 {
    /* code */
    int n;
    cin >> n;
    
    vector<int> ani(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ani[i];
    }
  
    int size =n;
    
    int counter=0;
  bool check[size];
   for(int i=0;i<size;i++){
      check[i] = 0;
   }
   for(int i=0; i<size; i++){
      if(check[i]== 1){
         continue;
      }
      int count = 1;
      for(int j = i+1; j<size; j++){
         if (ani[i] == ani[j]){
            check[j] = 1;
            count++;
         }
      }
      
      if(count %2 !=0){
       
         counter++;
      }
      
      
   }

    if(n%2 !=0){
        cout << "NO"<<endl;
    }
    else{
   if(counter > 1){
    cout << "NO"<<endl;
   }
   else{
    cout << "YES"<<endl;
   }
    }
   
    t--;

 }
 }
 
 
 
