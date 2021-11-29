#include <iostream>
#include <vector>
using namespace std;
using vI = vector<int>;


int get_levenshtein_dist(const string & s, const string & t)
{
    int height = s.length() + 1;
    int width = t.length() + 1;
    vector<vI> d(height, vI (width));

    for (int i = 0; i < height; ++i)
        for (int j = 0; j < width; ++j)
        {
            if (i == 0 or j == 0)
            {
                d[i][j] = i + j;
                continue;
            }

            if (s[i-1] != t[j-1])
            {
                d[i][j] = 1 + min(min(d[i-1][j], d[i][j-1]), d[i-1][j-1]);
                continue;
            }

            d[i][j] = d[i-1][j-1];
        }

    return d.back().back();
}


int main()
{
    string s;
    string t;
    cin >> s >> t;

    cout << get_levenshtein_dist(s, t) << endl;

    return 0;
}
