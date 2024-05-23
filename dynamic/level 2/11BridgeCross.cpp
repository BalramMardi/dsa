#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class CityPairs
{

public:
    int south;
    int north;

    CityPairs(int s, int n)
    {
        south = s;
        north = n;
    }
};

bool comp(CityPairs a, CityPairs b)
{

    if (a.north == b.north)
    {
        return a.south < b.south;
    }

    return a.north < b.north;
}

int overBrid(vector<CityPairs> &vec)
{

    vector<int> dp(vec.size());
    dp[0] = 1;

    sort(vec.begin(), vec.end(), comp);

    int omax = 0;
    for (int i = 1; i < vec.size(); i++)
    {
        int maxx = 0;
        for (int j = 0; j < i; j++)
        {
            if (vec[j].south < vec[i].south)
            {
                if (maxx < dp[j])
                {
                    maxx = dp[j];
                }
            }
        }

        dp[i] = maxx + 1;

        if (dp[i] > omax)
        {
            omax = dp[i];
        }
    }

    return omax;
}

int main()
{

    vector<CityPairs> vec = {{6, 2}, {4, 3}, {2, 6}, {1, 5}};

    int ans = overBrid(vec);
    cout << ans;
}