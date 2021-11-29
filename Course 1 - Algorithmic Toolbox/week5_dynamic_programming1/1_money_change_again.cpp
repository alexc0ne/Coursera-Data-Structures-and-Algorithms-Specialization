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
    vector<Int> minNumOfCoins(5);
    minNumOfCoins[0] = 0;
    minNumOfCoins[1] = 1; // 1 one-dollar coin
    minNumOfCoins[2] = 2; // 2 one-dollar coins
    minNumOfCoins[3] = 1; // 1 three-dollar coin
    minNumOfCoins[4] = 1; // 1 four-dollar coin

    if (n <= 4) return minNumOfCoins[n];

    for (Int i = 5; i <= n; ++i)
    {
        minNumOfCoins[i] = min3(minNumOfCoins[i - 1], minNumOfCoins[i - 3], minNumOfCoins[i - 4]) + 1;
    }

    return minNumOfCoins[n];
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
