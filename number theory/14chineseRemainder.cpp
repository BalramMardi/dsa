#include <iostream>
using namespace std;

class Pair
{
public:
    long long x;
    long long y;
    long long gcd;

    Pair(long long x, long long y, long long gcd) : x(x), y(y), gcd(gcd) {}
};

Pair euclids(long long a, long long b)
{
    if (b == 0)
    {
        return Pair(1, 0, a);
    }
    Pair dash = euclids(b, a % b);
    return Pair(dash.y, dash.x - ((a / b) * dash.y), dash.gcd);
}

int main()
{
    long long a1, n1, a2, n2;
    cin >> a1 >> n1 >> a2 >> n2;

    Pair p = euclids(n1, n2);
    long long x1 = p.x;
    long long gcd = p.gcd;

    if ((a1 - a2) % gcd != 0)
    {
        cout << "no solution" << endl;
    }
    else
    {
        long long lcm = (n1 / gcd) * n2;
        long long k = (a1 - a2) / gcd;

        long long ans = a1 - n1 * (k * x1 % (n2 / gcd));

        if (ans < 0)
        {
            ans += lcm;
        }

        cout << ans << " " << lcm << endl;
    }

    return 0;
}
