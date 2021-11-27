#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
using Int = uint64_t;


struct Item
{
    Int value_;
    Int weight_;
};


double MaximumValueOfTheLoot(Int numberOfItems, Int leftCapacity, const vector<Item> & items)
{
    double totalValue = 0;
    for (const auto & item : items)
    {
        if (leftCapacity == 0) break;

        if (item.weight_ < leftCapacity)
        {
            totalValue += item.value_;
            leftCapacity -= item.weight_;
        }
        else // item.weight_ > leftCapacity
        {
            totalValue += leftCapacity * static_cast<double> (item.value_) / item.weight_;
            leftCapacity = 0;
        }
    }

    return totalValue;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // read input ==================================
    Int numberOfItems = 0;
    Int knapsackCapacity = 0;
    cin >> numberOfItems >> knapsackCapacity;

    vector<Item> items(numberOfItems);
    Int itemValue = 0;
    Int itemWeight = 0;

    for (size_t i = 0; i < numberOfItems; i++)
    {
        cin >> itemValue >> itemWeight;
        items[i] = {itemValue, itemWeight};
    }


    // sort ========================================
    auto comparator = [](const Item & lhs, const Item & rhs)
    {
        return lhs.value_ * rhs.weight_ > rhs.value_ * lhs.weight_;
    };
    sort(items.begin(), items.end(), comparator);


    // display =====================================
    cout << fixed << setprecision(4) << MaximumValueOfTheLoot(numberOfItems, knapsackCapacity, items);

    return 0;
}
