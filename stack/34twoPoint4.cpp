
#include <bits/stdc++.h>
using namespace std;

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void find4Numbers(int A[], int n, int X)
{
    int l, r;

    qsort(A, n, sizeof(A[0]), compare);

    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
}
int main()
{
    int A[] = {1, 4, 45, 6, 10, 12};
    int X = 21;
    int n = sizeof(A) / sizeof(A[0]);
    find4Numbers(A, n, X);
    return 0;
}
