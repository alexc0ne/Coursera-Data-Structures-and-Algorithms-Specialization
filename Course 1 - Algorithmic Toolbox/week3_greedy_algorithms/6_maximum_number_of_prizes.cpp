#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
using Int = uint32_t;


string MaximumNumberOfPrizes(Int n)
{
    if (n == 1 || n == 2) return "1\n" + to_string(n);
    else // n > 0
    {
        --n;
        Int number_to_add = 2;
        vector<Int> res{1};

        while (number_to_add <= n)
        {
            res.push_back(number_to_add);
            n -= number_to_add;
            ++number_to_add;
        }

        res.back() += n;

        stringstream ss;
        ss << res.size() << "\n";
        for (const auto & item : res)
            ss << item << " ";

        return ss.str();
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    // read input ==================================

    Int n;
    cin >> n;

    // display =====================================

    cout << MaximumNumberOfPrizes(n);

    return 0;
}
