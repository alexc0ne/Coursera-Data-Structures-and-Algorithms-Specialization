#include <iostream>
#include <vector>
using namespace std;
using Int = int32_t;
using vI = vector<Int>;
using Matrix = vector<vI>;


/*
 * Attention!
 * Much easier to solve (even without filling the base) if we create matrix of size m+1, n+1 like this:
 *
 * . x 3 4 8 2
 * x 0 0 0 0 0
 * 4 0 . <-- starting point
 * 3 0
 * 1 0
 * 2 0
 * 
 */



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

    Matrix m (first.size(), vI (second.size(), 0));


	// base ========================================    
    /*
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
    
    if (first[0] == second[0]) m[0][0] = 1;
    
    for (size_t i = 1; i < first.size(); ++i)
        if (m[i-1][0] or first[i] == second[0]) m[i][0] = 1;

    for (size_t j = 1; j < second.size(); ++j)
        if (m[0][j-1] or second[j] == first[0]) m[0][j] = 1;


    // dynamic =====================================
    for (size_t i = 1; i < first.size(); ++i)
        for (size_t j = 1; j < second.size(); ++j)
        {
            // ('bacd', 'caab') --> max of 2 subtasks:
            // ('bacd', 'caa') and ('bac', 'caab')
            m[i][j] = max(m[i-1][j], m[i][j-1]);

            // ('abC', 'acC') --> 1 + max(('ab'), ('ac'))
            if (first[i] == second[j])
                m[i][j] = max(m[i][j], 1 + m[i-1][j-1]);
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
