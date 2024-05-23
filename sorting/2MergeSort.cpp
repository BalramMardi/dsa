#include <iostream>
#include <vector>

using namespace std;

vector<int> mergeSortedArrays(const vector<int> &arr1, const vector<int> &arr2)
{
    vector<int> mergedArray;
    int i = 0, j = 0;

    // Compare elements from both arrays and merge them
    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] < arr2[j])
        {
            mergedArray.push_back(arr1[i]);
            i++;
        }
        else
        {
            mergedArray.push_back(arr2[j]);
            j++;
        }
    }

    // Copy the remaining elements from both arrays
    while (i < arr1.size())
    {
        mergedArray.push_back(arr1[i]);
        i++;
    }

    while (j < arr2.size())
    {
        mergedArray.push_back(arr2[j]);
        j++;
    }

    return mergedArray;
}

vector<int> mergeSort(vector<int> &arr, int low, int high)
{

    // If the array has only one element, return it
    if (low == high)
        return {arr[low]};

    // Same as (left+right)/2, but avoids overflow for large left and right
    int middle = low + (high - low) / 2;

    vector<int> first = mergeSort(arr, low, middle);
    vector<int> second = mergeSort(arr, middle + 1, high);

    return mergeSortedArrays(first, second);
}

int main()
{
    vector<int> arr = {12, 1, 13, 5, 6, 7};

    cout << "Original array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }

    arr = mergeSort(arr, 0, arr.size() - 1);

    cout << "\nSorted array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }

    return 0;
}
