#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;


string MaximumSalary(vector<string> & nums)
{
    auto comparator = [](string a, string b)
    {
        if (stoi(a + b) > stoi(b + a)) return true;
        return false;
    };
    sort(nums.begin(), nums.end(), comparator);

    stringstream ss;
    for (const auto & item : nums)
        ss << item;

    return ss.str();
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    // read input ==================================

    size_t n;
    cin >> n;

    vector<string> nums(n);
    for (auto & item : nums)
        cin >> item;


    // display =====================================

    cout << MaximumSalary(nums);

    return 0;
}
