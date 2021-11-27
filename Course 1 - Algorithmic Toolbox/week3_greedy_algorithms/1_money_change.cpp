#include <iostream>
using namespace std;
using Int = uint32_t;


Int MoneyChange(Int m)
{
    Int numberOfCoins = 0;
    Int numberOfItems;
    for (auto item : {10, 5, 1})
    {
        numberOfItems = m / item;
        numberOfCoins += numberOfItems;
        m -= item * numberOfItems;
    }

    return numberOfCoins;
}



int main()
{
    Int m;
    cin >> m;

    cout << MoneyChange(m);

    return 0;
}
