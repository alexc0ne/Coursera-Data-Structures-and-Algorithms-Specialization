#include <iostream>
using namespace std;

unsigned fib_mod(unsigned fib_num)
{
    unsigned prev = 0, current = 1;

    if (fib_num == 0 || fib_num == 1)
    {
        return fib_num;
    }
    else
    {
        unsigned tmp = 0;
        for (size_t i = 2; i <= fib_num; i++)
        {
            tmp = (prev + current) % 10;
            prev = current;
            current = tmp;
        }
    }
    return current;
}

int main()
{
    unsigned fib_num = 0;
    cin >> fib_num;

    cout << fib_mod(fib_num) << endl;

    return 0;
}