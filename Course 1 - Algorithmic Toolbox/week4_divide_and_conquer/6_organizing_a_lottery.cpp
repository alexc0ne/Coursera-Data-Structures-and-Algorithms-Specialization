#include <iostream>
#include <vector>
using namespace std;
using Int = int32_t;


pair<Int, Int> partition3(size_t begin, size_t end, vector<Int> & v)
{
    // idx : [begin, end)
    size_t idx = rand() % (end - begin) + begin;
    Int pivot = v[idx];

    size_t begin_eq = begin;
    size_t begin_gr = begin;

    for (size_t i = begin; i != end; ++i)
    {
        if (v[i] > pivot) continue;

        if (v[i] == pivot)
        {
            swap(v[i], v[begin_gr]);
            ++begin_gr;
            continue;
        }

        // v[i] < pivot
        swap(v[i], v[begin_gr]);
        swap(v[begin_gr], v[begin_eq]);
        ++begin_eq;
        ++begin_gr;
    }

    return {begin_eq, begin_gr};
}


void sort(size_t begin, size_t end, vector<Int> & v)
{
    if (end - begin <= 1) return;

    pair<Int, Int> p = ::partition3(begin, end, v);

    ::sort(begin, p.first, v);
    ::sort(p.second, end, v);
}


void qsort(vector<Int> & v)
{
    size_t begin = 0;
    size_t end = v.size();

    ::sort(begin, end, v);
}



Int index_of_first_strict_greater(Int n, const vector<Int> & p)
{
    Int left = -1;
    Int right = p.size();

    Int mid;
    while (left + 1 < right)
    {
        mid = left + (right - left) / 2;

        if (p[mid] > n)
            right = mid;
        else
            left = mid;
    }

    return right;
}



Int index_of_first_greater_or_equal(Int n, const vector<Int> & p)
{
    Int left = -1;
    Int right = p.size();

    Int mid;
    while (left + 1 < right)
    {
        mid = left + (right - left) / 2;

        if (p[mid] >= n)
            right = mid;
        else
            left = mid;
    }

    return right;
}



int main()
{
    // accelerating the input ======================

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    // read input ==================================

    Int n, m;
    Int left, right;
    cin >> n >> m;

    vector<Int> lefts;
    vector<Int> rights;
    lefts.reserve(n);
    rights.reserve(n);

    for (Int i = 0; i < n; ++i)
    {
        cin >> left >> right;
        lefts.push_back(left);
        rights.push_back(right);
    }


    // display =====================================

    ::qsort(lefts);
    ::qsort(rights);

    Int num_left;
    Int num_right;

    for (Int i = 0; i < m; ++i)
    {
        cin >> n;
        num_left = index_of_first_strict_greater(n, lefts);
        num_right = index_of_first_greater_or_equal(n, rights);

        cout << abs(num_left - num_right) << " ";
    }

    return 0;
}
