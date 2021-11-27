#include <iostream>
using namespace std;

uint64_t fib(unsigned fib_num)
{
    uint64_t prev = 0, current = 1;

    if (fib_num == 0 || fib_num == 1)
    {
        return fib_num;
    }
    else
    {
        uint64_t tmp = 0;
        for (size_t i = 2; i <= fib_num; i++)
        {
            tmp = prev + current;
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

    cout << fib(fib_num) << endl;

    return 0;
}