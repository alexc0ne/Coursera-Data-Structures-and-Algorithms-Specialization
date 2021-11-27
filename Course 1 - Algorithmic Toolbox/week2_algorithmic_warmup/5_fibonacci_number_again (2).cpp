// С этой задачей возникли проблемы на Stepik'е, в то время как на Курсере
// была принята более медленная версия.
// На степике условия более жесткие: 1 <= fib_num <= 10^18, 2 <= mod <= 10^5.
// На Курсере 2 <= mod <= 10^3.

#include <iostream>
#include <vector>
using namespace std;

vector<unsigned> fib(unsigned mod)
{
    vector<unsigned> v = {0,1};

    unsigned tmp = 0, prev = 0, current = 1;
    size_t counter = 2;
    while (true)
    {
        tmp = (prev + current) % mod;
        prev = current;
        current = tmp;
        v.push_back(current);
        if (v[counter] == 1 && v[counter - 1] == 0)
        {
            break;
        }
        counter++;
    }

    return v;
}

int main()
{
    uint64_t fib_num = 0;
    unsigned mod = 0;
    cin >> fib_num >> mod;

    vector<unsigned> v = fib(mod);

    if (fib_num == 1)
    {
        cout << 1 << endl;
    }
    else
    {
        fib_num %= static_cast<uint64_t>(v.size() - 2);
        cout << v[fib_num] << endl;
    }

    return 0;
}