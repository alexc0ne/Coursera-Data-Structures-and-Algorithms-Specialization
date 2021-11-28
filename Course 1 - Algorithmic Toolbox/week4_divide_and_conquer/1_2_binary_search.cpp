#include <iostream>
#include <vector>
using namespace std;
using Int = int32_t;
using vI = vector<Int>;


void readToVector(vI & v)
{
    for (auto & item : v)
        cin >> item;
}


Int BinarySearch(Int x, const vI & sorted)
{
    Int left = -1;
    Int right = sorted.size();
    Int mid;

    while (left + 1 < right)
    {
        mid = left + (right - left) / 2;

        // search invariants:
        //     sorted[right] >= x
        //     sorted[left] < x

        if (sorted[mid] < x)
            left = mid;
        else // sorted[mid] >= x
            right = mid;
    }

    if (right == sorted.size() or sorted[right] != x) return -1;
    return right;
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

    vI sortedArray(n);
    readToVector(sortedArray);

    Int k;
    cin >> k;

    vI queries(k);
    readToVector(queries);


    // display =====================================

    for (auto item : queries)
        cout << BinarySearch(item, sortedArray) << " ";


    return 0;
}
