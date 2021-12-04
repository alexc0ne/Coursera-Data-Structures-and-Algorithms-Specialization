/*
 * this algorithm was presented by the lecturer
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using Int = int64_t;
using vI = vector<Int>;



Int CarFueling(Int distance, Int numOfGasStations, const vI & path)
{
    Int numRefills = 0;
    Int currentRefill = 0;
    Int lastRefill;

    while (currentRefill <= numOfGasStations)
    {
        lastRefill = currentRefill;
        while (currentRefill <= numOfGasStations and
               path[currentRefill + 1] - path[lastRefill] <= distance)
        {
            ++currentRefill;
        }

        if (currentRefill == lastRefill) return -1;
        if (currentRefill <= numOfGasStations) ++numRefills;
    }

	return numRefills;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // read input ==================================

    Int destination, distance, numOfGasStations;
    cin >> destination >> distance >> numOfGasStations;

    vI path(numOfGasStations + 2, 0);
    path.back() = destination;

    for (size_t i = 1; i <= numOfGasStations; ++i)
        cin >> path[i];

    // display =====================================

    cout << CarFueling(distance, numOfGasStations, path);

    return 0;
}
