#include <iostream>
#include <string>

void solveConfiguration(char arr[], int i, int j)
{
    if (arr[i] == 'L' && arr[j] == 'L')
    {
        for (int k = i + 1; k < j; k++)
            arr[k] = 'L';
    }
    else if (arr[i] == 'R' && arr[j] == 'R')
    {
        for (int k = i + 1; k < j; k++)
            arr[k] = 'R';
    }
    else if (arr[i] == 'L' && arr[j] == 'R')
    {
        // nothing to do
    }
    else
    {
        int diff = j - i;
        if (diff % 2 == 0)
        {
            int mid = (i + j) / 2;
            for (int k = i + 1; k < mid; k++)
                arr[k] = 'R';

            for (int k = mid + 1; k < j; k++)
                arr[k] = 'L';
        }
        else
        {
            int mid = (i + j) / 2;
            for (int k = i + 1; k <= mid; k++)
                arr[k] = 'R';

            for (int k = mid + 1; k < j; k++)
                arr[k] = 'L';
        }
    }
}

std::string pushDominoes(std::string str)
{
    int n = str.length();
    char arr[n + 2];
    arr[0] = 'L';
    arr[n + 1] = 'R';
    for (int i = 1; i <= n; i++)
    {
        arr[i] = str[i - 1];
    }
    int j = 0, k = 1;
    while (k <= n + 1)
    {
        while (arr[k] == '.')
        {
            k++;
        }
        if (k - j > 1)
            solveConfiguration(arr, j, k);
        j = k;
        k++;
    }
    std::string res = "";
    for (int i = 1; i <= n; i++)
    {
        res += arr[i];
    }
    return res;
}

int main()
{
    std::string str;
    std::cin >> str;
    std::string res = pushDominoes(str);
    std::cout << res << std::endl;
    return 0;
}
