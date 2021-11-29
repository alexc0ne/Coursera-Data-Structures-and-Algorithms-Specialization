#include <iostream>
#include <vector>
using namespace std;
using Int = int32_t;
using vI = vector<Int>;


pair<Int, vI> primitive_calculator(Int n)
{
    if (n == 1)
        return {0, {1}};

    if (n == 2 or n == 3)
        return {1, {n, 1}};

    vector<Int> v(n + 1, 0);
    v[1] = 0;
    v[2] = 1;
    v[3] = 1;

    size_t Size = n + 1;
    Int n2, n3;
    for (size_t i = 4; i < Size; ++i)
    {
        n2 = v[i/2] + i % 2 + 1;
        n3 = v[i/3] + i % 3 + 1;
        v[i] = min(n2, n3);
    }

    vI path;

    size_t n0;
    while (n > 1)
    {
        path.push_back(n);

        if (v[n / 3] + n % 3 <= v[n / 2] + n % 2) // took away +1 from both sides but it's there!
        {
            n0 = n % 3;
            for (size_t i = 0; i < n0; ++i)
                path.push_back(--n);

            n /= 3;
        }
        else
        {
            n0 = n % 2;
            for (size_t i = 0; i < n0; ++i)
                path.push_back(--n);

            n /= 2;
        }
    }
    path.push_back(1);

    return {v.back(), path};
}


int main()
{
    Int n;
    cin >> n;

    auto ans = primitive_calculator(n);
    cout << ans.first << endl;
    for (auto it = ans.second.rbegin(); it != ans.second.rend(); ++it)
        cout << *it << " ";

    return 0;
}
