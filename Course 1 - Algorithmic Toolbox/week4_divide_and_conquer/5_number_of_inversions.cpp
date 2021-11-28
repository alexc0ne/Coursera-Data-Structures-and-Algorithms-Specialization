#include <iostream>
#include <vector>
using namespace std;
using Int = uint32_t;
using vI = vector<Int>;


Int cnt = 0;


void readToVector(vI & v)
{
    for (auto & item : v)
        cin >> item;
}


vI merge(const vI & a, const vI & b)
{
    Int i = 0;
    Int j = 0;
    vI res(a.size() + b.size());

    for (Int & item : res)
    {
        if (j == b.size() or (i < a.size() and a[i] <= b[j]))
        {
            item = a[i];
            ++i;
        }
        else
        {
            // we go here only and only if a[i] > b[j] ==>
            // a[i] > b[j], a[i+1] > b[j], a[i+2] > b[j], ... , a.back() > b[j]
            // that is there are (a.size() - i) elements greater than b[j]
            // and thus ==> (a.size() - i) inversions

            cnt += a.size() - i;
            item = b[j];
            ++j;
        }
    }

    return res;
}


vI merge_sort(const vI & v)
{
    if (v.size() == 1)
        return v;

    Int mid = v.size() / 2;
    vI left(v.begin(), v.begin() + mid);
    vI right(v.begin() + mid, v.end());

    left = merge_sort(left);
    right = merge_sort(right);

    return merge(left, right);
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

    vI v(n);
    readToVector(v);


    // display =====================================


	merge_sort(v);
	cout << cnt;


    return 0;
}
