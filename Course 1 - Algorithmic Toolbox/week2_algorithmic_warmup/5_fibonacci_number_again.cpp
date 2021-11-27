#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

unsigned fib(uint64_t fib_num, unsigned mod)
{
    unsigned prev = 0, current = 1;

    if (fib_num == 0 || fib_num == 1)
    {
        return static_cast<unsigned>(fib_num);
    }
    else
    {
        unsigned tmp = 0;
        for (size_t i = 2; i <= fib_num; i++)
        {
            tmp = (prev + current) % mod;
            prev = current;
            current = tmp;
        }
    }
    return current;
}

unsigned process(uint64_t fib_num, unsigned mod)
{
    if (fib_num == 1)
    {
        return 1;
    }
    else
    {
        uint64_t counter = 2;
        unsigned prev = 0, current = 1;
        while (true)
        {
            prev = current;
            current = fib(counter, mod);
            counter++;

            if (prev == 0 && current == 1)
            {
                break;
            }
        }

        fib_num %= (counter - 2);
        return fib(fib_num, mod);
    }
}

int main()
{
    for (size_t i = 1; i <= 1000000000000000000; i++)
    {
        cout << i << endl;
        for (unsigned j = 2; j <= 100000; j++)
        {
            auto start = steady_clock::now();
            process(i, j);
            auto finish = steady_clock::now();
            if (duration_cast<milliseconds>(finish - start).count() >= 1000)
            {
                cout << "not successful" << endl;
                cout << "n = " << i << endl;
                cout << "mod = " << j << endl;
                break;
            }
        }
    }

    cout << "END" << endl;

    return 0;
}