#include <iostream>
using namespace std;

int power(long long x, unsigned int y, int p)
{
    int res = 1;

    x = x % p;
    if (x == 0)
        return 0;

    while (y > 0)
    {

        if (y & 1) // to check for odd number
        {
            res = (res * x) % p;
            y--;
        }

        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

int main()
{
    // int x = 10;
    int x = 2;

    // int y = 5;
    int y = 5;

    // int p = 1000000007;
    int p = 13;

    cout << "Power is " << power(x, y, p);
    return 0;
}
