#include <iostream> 
#include <bits/stdc++.h>
using namespace std;

class dog{
    public:
    string name1="";
    int age2=0;
    int height3=0;

    /* dog(string name,int age,int height){
        this->name=name;
        this->age=age;
        this->height=height;
    } */
    dog(string name,int age,int height){
        name1=name;
        age2=age;
        height3=height;
    }
};
int main()
{
 /* vector<dog> id;
 id.push_back(dog("apple",14,20));
 id.push_back(dog("willyt",17,25));
 for (auto x : id)
 {
    cout << x.name << " " << x.age << endl;
 }
 cout << id[0].name << " " << id[1].age << endl; */


 queue<dog> q;
 q.push(dog("jelly",15,22));
 q.push(dog("dusky",18,25));
 q.front();
 q.pop();
 dog ok1 = q.front();
  // cout << ok1.name;
  int siz= q.size();
 cout << q.front().name1 << q.front().height3 << " "<< siz << endl;


 
 
}