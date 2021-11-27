#include <iostream>
using namespace std;

uint64_t fib(uint64_t fib_num)
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
            tmp = (prev + current) % 10;
            prev = current;
            current = tmp;
        }
    }
    return current;
}

int main()
{
    uint64_t num = 0;
    cin >> num;
    num %= 60;

    cout << (fib(num) * fib(num + 1)) % 10 << endl;

    return 0;
}