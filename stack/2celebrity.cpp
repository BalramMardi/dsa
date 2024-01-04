#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void celebrity(int arr[4][4])
{
    stack<int> st;
    for (int i = 0; i < 4; i++)
    {
        st.push(i);
    }

    while (st.size() > 1)
    {
        int i = st.top();
        st.pop();
        int j = st.top();
        st.pop();
        if (arr[i][j] == 1)
        {
            st.push(j);
        }
        else
            st.push(i);
    }

    int pot = st.top();
    for (int i = 0; i < 4; i++)
    {
        if (i != pot)
        {
            if (arr[i][pot] == 0 or arr[pot][i] == 1)
            {
                cout << "none" << endl;
                return;
            }
        }
    }
    cout << pot << endl;
}

int main()
{

    int arr[4][4] = {{0, 1, 1, 0},
                     {0, 0, 0, 0},
                     {0, 1, 1, 0},
                     {0, 1, 1, 0}};

    celebrity(arr);
}