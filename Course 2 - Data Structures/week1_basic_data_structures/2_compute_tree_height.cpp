#include <iostream>
#include <vector>
#include <stack>
using namespace std;
using Int = int32_t;
using vI = vector<Int>;
using vvI = vector<vI>;


vI ReadInput(Int & root_idx)
{
    Int n;
    cin >> n;

    vI nodes(n);

    Int tmp;
    for (Int i = 0; i < n; ++i)
    {
        cin >> tmp;
        if (tmp == -1) root_idx = i;
        nodes[i] = tmp;
    }

    return nodes;
}


vvI MakeAdjacencyList(const vI & nodes)
{
    vvI adjacencyList(nodes.size());

    for (Int i = 0; i < nodes.size(); ++i)
    {
        if (nodes[i] >= 0)
            adjacencyList[nodes[i]].push_back(i);
    }

    return adjacencyList;
}


Int TreeHeight(Int root_idx, const vI & nodes)
{
    vvI adjacencyList = MakeAdjacencyList(nodes);


    // if root has no children
    if (adjacencyList[root_idx].empty()) return 1;


    // root has children
    vI height(nodes.size(), 1);
    stack<Int> pile;


    // adding all the root children to the stack
    for (auto item : adjacencyList[root_idx])
        pile.push(item);


    // DFS without recursion
    Int current_idx;
    Int current_max = 1;
    while (!pile.empty())
    {
        current_idx = pile.top();
        pile.pop();

        height[current_idx] = 1 + height[nodes[current_idx]];
        current_max = max(current_max, height[current_idx]);

        if (!adjacencyList[current_idx].empty())
            for (auto item : adjacencyList[current_idx])
                pile.push(item);
    }


    return current_max;
}


int main()
{
    // accelerating the input ======================

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    // read input ==================================

    Int root_idx;
    vI nodes = ReadInput(root_idx);

    // display =====================================

    vvI adjacencyList = MakeAdjacencyList(nodes);
    cout << TreeHeight(root_idx, nodes);

    return 0;
}
