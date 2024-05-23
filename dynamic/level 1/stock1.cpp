#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {

        int lsf = INT_MAX;
        int pist = 0;
        int op = 0;

        for (int i = 0; i < prices.size(); i++)
        {
            if (lsf > prices[i])
            {
                lsf = prices[i];
            }

            pist = prices[i] - lsf;

            if (pist > op)
            {
                op = pist;
            }
        }
        return op;
    }
};

int main()
{
}