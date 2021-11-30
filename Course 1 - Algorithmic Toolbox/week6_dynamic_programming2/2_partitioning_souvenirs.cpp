/*
 * Solution based on the following script:
 *
 * https://www.cse.iitd.ac.in/~naveen/courses/CSL630/Q6.pdf
 *
 * */


#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
using Int = int32_t;
using vI = vector<Int>;
using Matrix = vector<vector<vI>>;


Int SouvenirsPartition(vI & items)
{
    // checkings =====================================

    if (items.size() < 3) return 0;

    Int sum = accumulate(items.begin(), items.end(), 0);
    if (sum % 3 != 0) return 0;

    sum /= 3;
    for (const auto & item : items)
    {
        if (item > sum) return 0;
    }

    Matrix m (items.size(), vector<vI> (sum + 1, vI (sum + 1)));
    m[0][0][0] = 1;

    for (Int i = 1; i < items.size(); ++i)
        for (Int j = 0; j <= sum; ++j)
            for (Int k = 0; k <= sum; ++k)
            {
                if (m[i-1][j][k])
                {
                    m[i][j][k] = 1;
                    continue;
                }

                if (j - items[i] >= 0 and m[i-1][j-items[i]][k])
                {
                    m[i][j][k] = 1;
                    continue;
                }

                if (k - items[i] >= 0 and m[i-1][j][k-items[i]])
                {
                    m[i][j][k] = 1;
                    continue;
                }

                // not really necessary, left for readability
                m[i][j][k] = 0;
            }

    return m.back().back().back();
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

    vI items(n + 1, 0);
    for (size_t i = 1; i <= n; ++i)
        cin >> items[i];

    // display =====================================

    cout << SouvenirsPartition(items);

    return 0;
}
