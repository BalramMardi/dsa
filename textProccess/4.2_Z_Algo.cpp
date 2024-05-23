#include <iostream>
#include <vector>

using namespace std;

void create_Zarr(const string &str, vector<int> &Z)
{
    int n = str.length();
    int left, right;

    left = right = 0;
    for (int i = 0; i < n; i++)
    {
        if (i <= right)
        {
            Z[i] = min(right - i + 1, Z[i - left]);
        }

        while (i + Z[i] < n && str[Z[i]] == str[i + Z[i]])
            Z[i]++;

        if (i + Z[i] - 1 > right)
        {
            left = i;
            right = left + Z[i] - 1;
        }
    }
}

void findPatternIndices(const string &text, const string &pattern)
{
    string concat = pattern + "$" + text;
    int l = concat.length();

    // Convert Z array to vector
    vector<int> Z(l, 0);
    create_Zarr(concat, Z);

    for (int i = 1; i < l; i++)
    {
        if (Z[i] == pattern.length())
            cout << "Pattern found at index " << i - pattern.length() - 1 << endl;
    }
}

int main()
{
    string text = "faabbcdeffghiaaabbcdfgaabf";
    string pattern = "aabb";
    findPatternIndices(text, pattern);
    return 0;
}
