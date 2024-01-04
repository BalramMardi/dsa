#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> vec(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> vec[i][j];
        }
    }

    // 1.get x coordinate

    vector<int> xcor;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vec[i][j] == 1)
            {
                xcor.push_back(i);
            }
        }
    }

    // 2.get y coordinate

    vector<int> ycor;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vec[j][i] == 1)
            {
                ycor.push_back(i);
            }
        }
    }
    // 3.mid

    int mid = xcor.size() / 2;
    int xmid = xcor[mid];
    int ymid = ycor[mid];

    // 4.cal dist

    int dist = 0;

    for (auto xval : xcor)
    {
        dist += abs(xmid - xval);
    }

    for (auto yval : ycor)
    {
        dist += abs(ymid - yval);
    }
    // 5.return
    cout << dist;
}