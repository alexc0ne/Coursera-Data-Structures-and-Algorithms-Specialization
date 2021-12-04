/*
 * this algorithm was presented by the lecturer
 */

#include <iostream>
#include <vector>
#include <limits>
using namespace std;
using Int = int64_t;
using vI = vector<Int>;
using vC = vector<char>;
using Matrix = vector<vI>;


struct Pair
{
    Int min_;
    Int max_;
};


Int ComputeExpression(Int left, char op, Int right)
{
    if (op == '+')
        return left + right;
    if (op == '-')
        return left - right;
    if (op == '*')
        return left * right;

    throw runtime_error("forbidden operation: " + to_string(op));
}


Pair MinAndMax(size_t i, size_t j, const Matrix & m, const Matrix & M, const vC & operations)
{
    Int maxInt = numeric_limits<Int>::min();
    Int minInt = numeric_limits<Int>::max();

    Int a, b, c, d;
    for (size_t k = i; k < j; ++k)
    {
        a = ComputeExpression(M[i][k], operations[k], M[k+1][j]);
        b = ComputeExpression(M[i][k], operations[k], m[k+1][j]);
        c = ComputeExpression(m[i][k], operations[k], M[k+1][j]);
        d = ComputeExpression(m[i][k], operations[k], m[k+1][j]);

        minInt = min(minInt, min(min(a, b), min(c, d)));
        maxInt = max(maxInt, max(max(a, b), max(c, d)));
    }

    return {minInt, maxInt};
}


Int MaxValArithmeticExpression(const vI & digits, const vC & operations)
{
    Matrix m(digits.size(), vI (digits.size())); // matrix of min values
    Matrix M(digits.size(), vI (digits.size())); // matrix of max values

    for (size_t i = 0; i < digits.size(); ++i)
    {
        m[i][i] = digits[i];
        M[i][i] = digits[i];
    }

    size_t j;
    Pair tmp;
    for (size_t s = 1; s < digits.size(); ++s)
        for (size_t i = 0; i + s < digits.size(); ++i)
        {
            j = i + s;
            tmp = MinAndMax(i, j, m, M, operations);
            m[i][j] = tmp.min_;
            M[i][j] = tmp.max_;
        }

    return M[0].back();
}


int main()
{
    // accelerating the input ======================

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    // read input ==================================

    vI digits;
    vC operations;

    string expression;
    cin >> expression;

    for (size_t i = 0; i < expression.size(); ++i)
    {
        // if expression[i] is a digit
        if (i % 2 == 0)
            digits.push_back(expression[i] - '0');
        else
            operations.push_back(expression[i]);
    }


    // display =====================================

    cout << MaxValArithmeticExpression(digits, operations);


    return 0;
}
