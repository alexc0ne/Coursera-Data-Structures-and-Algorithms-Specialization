#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using Int = uint32_t;
using vI = vector<Int>;


struct Segment
{
    Int left, right;
};


void CollectingSignatures(const vector<Segment> & segments)
{
    size_t n = segments.size();
    vI ans;

    bool flag1 = false, flag2 = false;
    size_t index = 0;

    while (!flag1 && !flag2)
    {
        Segment current_basis = segments[index];
        
        if (index == n - 1) flag1 = true;
        ans.push_back(current_basis.right);
        
        for (size_t j = index + 1; j < n; j++)
        {
            if (current_basis.right < segments[j].left)
            {
                index = j;
                break;
            }
            else if (j == n - 1) flag2 = true;
        }
    }
    
    cout << ans.size() << endl;
    for (auto item : ans)
        cout << item << " ";
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    // read input ==================================

    Int n;
    cin >> n;

    vector<Segment> segments(n);
    for (auto & item : segments)
        cin >> item.left >> item.right;


    // sort ========================================

    auto comparator = [](Segment a, Segment b) { return a.right < b.right; };
    sort(segments.begin(), segments.end(), comparator);


    // display =====================================

    CollectingSignatures(segments);

    return 0;
}
