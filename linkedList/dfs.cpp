#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int func(int **id, int **num)
{
    cout << **id << endl;
    cout << **num << endl;

    return **id;
}
int main()
{

    int id = 8;
    int *pid = &id;
    int num = 9;
    int *pnum = &num;

    int k = func(&pid, &pnum);
    cout << "k-> " << k;
}