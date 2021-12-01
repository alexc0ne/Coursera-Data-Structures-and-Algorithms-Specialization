#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using Int = int32_t;
using vI = vector<Int>;
using Matrix = vector<vector<vI>>;

/*
 * 
 * Attention!
 * 
 * This task can be solved much easily, if we create matrix of size m+1, n+1, k+1 instead of m,n,k.
 * The algorithm will then fill the base automatically.
 * 
 * */



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


void FindAndFill(Matrix & m, const vI & a,
                             const vI & b,
                             Int element,
                             Int coord)
{
    auto it1 = find(a.begin(), a.end(), element);
    auto it2 = find(b.begin(), b.end(), element);
    for (size_t idx1 = it1 - a.begin(); idx1 < a.size(); ++idx1)
        for (size_t idx2 = it2 - b.begin(); idx2 < b.size(); ++idx2)
        {
            if (coord == 3)
                m[idx1][idx2][0] = 1;
            else if (coord == 2)
                m[idx1][0][idx2] = 1;
            else if (coord == 1)
                m[0][idx1][idx2] = 1;
            else
                throw runtime_error("coord is out of range");
        }
}


Int CommonSubsequenceOfThree(const vI & first, const vI & second, const vI & third)
{
    if (first.empty() or second.empty() or third.empty()) return 0;

    Matrix m (first.size(), vector<vI> (second.size(), vI (third.size())));

    /*
     * an example for 2d case
     * 3d case is analogous, but we have to fill all the initial (base) surfaces,
     * i.e. XY, XZ, YZ
     *
     *   A C B B C A
     * B 0 0 1 1 1 1
     * A 1
     * C 1
     *
     * id est (B, A) = 0
     *        (B, AC) = 0
     *        (B, ACB) = 1
     *        (B, ACBB) = 1 and so on.
     *
     * */


    // base
    FindAndFill(m, first, second, third[0], 3);
    FindAndFill(m, first, third, second[0], 2);
    FindAndFill(m, second, third, first[0], 1);


    // dynamic
    for (size_t i = 1; i < first.size(); ++i)
        for (size_t j = 1; j < second.size(); ++j)
            for (size_t k = 1; k < third.size(); ++k)
            {
                m[i][j][k] = max3(m[i-1][j][k],
                                  m[i][j-1][k],
                                  m[i][j][k-1]);

                if (first[i] == second[j] and first[i] == third[k])
                    m[i][j][k] = max(m[i][j][k],
                                     m[i-1][j-1][k-1] + 1);
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
