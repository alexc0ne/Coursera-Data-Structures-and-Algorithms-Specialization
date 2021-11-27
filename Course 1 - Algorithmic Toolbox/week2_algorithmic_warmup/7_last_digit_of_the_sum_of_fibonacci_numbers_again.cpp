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
    uint64_t num1 = 0, num2 = 0;
    cin >> num1 >> num2;
    num1 += 1;
    num2 += 2;
    num1 %= 60;
    num2 %= 60;

    uint64_t a2 = fib(num2) + 19;
    uint64_t a1 = fib(num1) + 9;

    cout << (a2 - a1) % 10 << endl;

    return 0;
}