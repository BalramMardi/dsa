#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int func(int *&id, int *num)
{
    cout << id << endl;
    cout << num << endl;

    return *id;
}
int main()
{

    int *id = NULL;
    int num = 9;

    int k = func(id, &num);
    cout << "k-> " << k;
}