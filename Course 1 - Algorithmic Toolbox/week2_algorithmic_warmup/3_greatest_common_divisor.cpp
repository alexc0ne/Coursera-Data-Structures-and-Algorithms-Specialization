#include <iostream>
using namespace std;

unsigned gcd(unsigned a, unsigned b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int main()
{
    unsigned a = 0, b = 0;
    cin >> a >> b;

    cout << gcd(a, b) << endl;

    return 0;
}