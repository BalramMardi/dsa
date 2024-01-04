#include <iostream>

long long gcd(long long a, long long b, long long &x, long long &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int main()
{
    long long a1, n1, a2, n2;
    std::cin >> a1 >> n1 >> a2 >> n2;

    long long x1, gcdValue, y1;
    gcdValue = gcd(n1, n2, x1, y1);

    if ((a1 - a2) % gcdValue != 0)
    {
        std::cout << "no solution" << std::endl;
    }
    else
    {
        long long lcm = (n1 / gcdValue) * n2;
        long long k = (a1 - a2) / gcdValue;

        long long ans = a1 - n1 * (k * x1 % (n2 / gcdValue));

        if (ans < 0)
        {
            ans += lcm;
        }

        std::cout << ans << " " << lcm << std::endl;
    }

    return 0;
}
