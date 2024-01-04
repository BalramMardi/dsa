#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void transpose(vector<vector<int>> &matrix)
{

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

void reversem(vector<vector<int>> &matrix)
{

    for (int i = 0; i < matrix.size(); i++)
    {
        int left = 0;
        int right = matrix.size() - 1;

        while (left < right)
        {
            swap(matrix[i][right], matrix[i][left]);
            left++;
            right--;
        }
    }
}

void rotate(vector<vector<int>> &matrix)
{

    // 1.transpose
    transpose(matrix);
    // 2.reverse
    reversem(matrix);
}
int main()
{
    vector<vector<int>> matrix;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    rotate(matrix);
}