#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxFrequency(const vector<int> &nums, int k)
{
    vector<int> sortedNums(nums.begin(), nums.end());

    sort(sortedNums.begin(), sortedNums.end());

    int left = 0;
    int maxFreq = 0;
    long long sum = 0;

    for (int right = 0; right < sortedNums.size(); right++)
    {
        sum += sortedNums[right];

        // Shrink the window if the sum exceeds k
        while ((right - left + 1) * sortedNums[right] > k + sum)
        {
            sum -= sortedNums[left];
            left++;
        }

        maxFreq = max(maxFreq, right - left + 1);
    }

    return maxFreq;
}

int main()
{
    // vector<int> nums = {1, 2, 4};
    vector<int> nums = {1, 1, 1, 2, 2, 4};

    int k = 2;

    int maxFreq = maxFrequency(nums, k);
    cout << "Maximum frequency: " << maxFreq << endl;

    return 0;
}
