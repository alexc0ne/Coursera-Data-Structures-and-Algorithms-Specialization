#include <iostream>
#include <vector>
using namespace std;
using Int = int32_t;


Int min3(Int a, Int b, Int c)
{
    return min(min(a, b), c);
}


Int MoneyChange(Int n)
{
    vector<Int> numOfCoins(5);
    numOfCoins[0] = 0;
    numOfCoins[1] = 1; // 1 one-dollar coin
    numOfCoins[2] = 2; // 2 one-dollar coins
    numOfCoins[3] = 1; // 1 three-dollar coin
    numOfCoins[4] = 1; // 1 four-dollar coin

    if (n <= 4) return numOfCoins[n];

    for (Int i = 5; i <= n; ++i)
    {
        numOfCoins[i] = min3(numOfCoins[i-1], numOfCoins[i-3], numOfCoins[i-4]) + 1;
    }

    return numOfCoins[n];
}


int main()
{
    // accelerating the input ======================

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    // read input ==================================

    Int n;
    cin >> n;


    // display =====================================

    cout << MoneyChange(n);

    return 0;
}
