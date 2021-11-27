#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using Int = int64_t;
using vI = vector<Int>;


Int MaximumAdvertisementRevenue(vI & first, vI & second)
{
    sort(first.begin(), first.end());
    sort(second.begin(), second.end());

    // dot product in essence

    Int res = 0;
    for (size_t i = 0; i < first.size(); ++i)
        res += first[i] * second[i];

    return res;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    // read input ==================================

    Int numberOfAds;
    cin >> numberOfAds;

    vector<Int> firstLine(numberOfAds);
    vector<Int> secondLine(numberOfAds);

    for (auto & item : firstLine) cin >> item;
    for (auto & item : secondLine) cin >> item;


    // display =====================================

    cout << MaximumAdvertisementRevenue(firstLine, secondLine);

    return 0;
}
