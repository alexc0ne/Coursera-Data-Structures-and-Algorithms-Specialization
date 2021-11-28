#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using Int = int32_t;
using vI = vector<Int>;


void readToVector(vI & v)
{
    for (auto & item : v)
        cin >> item;
}


Int MajorityElement(const vI & v)
{
    if (v.size() == 1) return 1;

    Int cnt = 1;
    for (size_t i = 1; i < v.size(); ++i)
    {
        if (v[i] == v[i-1])
        {
            ++cnt;
            if (cnt > v.size() / 2) return 1;
            continue;
        }

        cnt = 1;
    }

    return 0;
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
    sort(v.begin(), v.end());


    // display =====================================

    cout << MajorityElement(v);


    return 0;
}
