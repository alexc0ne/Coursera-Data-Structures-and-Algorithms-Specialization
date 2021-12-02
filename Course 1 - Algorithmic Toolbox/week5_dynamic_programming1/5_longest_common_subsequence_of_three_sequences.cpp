#include <iostream>
#include <vector>
using namespace std;
using Int = int32_t;
using vI = vector<Int>;
using Matrix = vector<vector<vI>>;


Int max3(Int a, Int b, Int c)
{
    return max(a, max(b, c));
}


vI ReadVector()
{
    Int n;
    cin >> n;

    vI v(n);
    for (auto & item : v) cin >> item;

    return v;
}


Int CommonSubsequenceOfThree(const vI & first, const vI & second, const vI & third)
{
    if (first.empty() or second.empty() or third.empty()) return 0;

    Matrix m (first.size() + 1, vector<vI> (second.size() + 1, vI (third.size() + 1)));


    // dynamic
    for (size_t i = 1; i <= first.size(); ++i)
        for (size_t j = 1; j <= second.size(); ++j)
            for (size_t k = 1; k <= third.size(); ++k)
            {
                if (first[i-1] == second[j-1] and first[i-1] == third[k-1])
                {
                    m[i][j][k] = m[i-1][j-1][k-1] + 1;
                    continue;
                }

                m[i][j][k] = max3(m[i-1][j][k], m[i][j-1][k], m[i][j][k-1]);
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

    vI first = ReadVector();
    vI second = ReadVector();
    vI third = ReadVector();


    // display =====================================

    cout << CommonSubsequenceOfThree(first, second, third);

    return 0;
}
