#include <iostream>
#include <vector>
using namespace std;
using Int = int32_t;
using vI = vector<Int>;
using Matrix = vector<vI>;


vI ReadVector()
{
    Int n;
    cin >> n;

    vI v(n);
    for (auto & item : v) cin >> item;

    return v;
}


Int CommonSubsequenceOfTwo(const vI & first, const vI & second)
{
    if (first.empty() or second.empty()) return 0;
    Matrix m (first.size() + 1, vI (second.size() + 1, 0));

    // base (automatically) ========================
    /*
     *
     *   0 A C B B C A
     * 0 0 0 0 0 0 0 0
     * B 0
     * A 0
     * C 0
     *
     *
     * */

    // dynamic =====================================
    for (size_t i = 1; i <= first.size(); ++i)
        for (size_t j = 1; j <= second.size(); ++j)
        {
            // ('abC', 'acC') --> 1 + max(('ab'), ('ac'))
            if(first[i-1] == second[j-1])
            {
                m[i][j] = m[i-1][j-1] + 1;
                continue;
            }

            // ('bacd', 'caab') --> max of 2 subtasks:
            // ('bacd', 'caa') and ('bac', 'caab')
            m[i][j] = max(m[i-1][j], m[i][j-1]);
        }

    return m.back().back();
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


    // display =====================================

    cout << CommonSubsequenceOfTwo(first, second);

    return 0;
}
