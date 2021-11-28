#include <iostream>
#include <chrono>
#include <random>
#include <stack>
using namespace std;
using Int = uint32_t;
using vI = vector<Int>;
using pII = pair<Int, Int>;


size_t get_random_in_range(size_t begin, size_t end)
{
    // easier way: rand() % n : [0, n)
    // size_t r = rand() % (end - begin) + begin;

    auto seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine e(seed);
    uniform_int_distribution<size_t> u(begin, end - 1);

    return u(e);
}


pII partition3(size_t begin, size_t end, vI & a)
{
    size_t idx = get_random_in_range(begin, end);
    Int pivot = a[idx];


    size_t begin_eq = begin;
    size_t begin_gr = begin;


    for (size_t i = begin; i < end; ++i)
    {
        if (a[i] > pivot) continue;

        if (a[i] == pivot)
        {
            swap(a[begin_gr], a[i]);
            ++begin_gr;
            continue;
        }

        //if (a[i] < pivot)
        swap(a[begin_gr], a[i]);
        swap(a[begin_eq], a[begin_gr]);
        ++begin_eq;
        ++begin_gr;
    }

    return {begin_eq, begin_gr};
}


// without recursion
void sort(size_t begin, size_t end, vI & a)
{
    stack<pII> pending;
    pending.emplace(begin, end);
    pII curr;
    pII part;
    while (!pending.empty())
    {
        curr = pending.top();
        pending.pop();
        if (curr.second - curr.first <= 1) continue;
        part = partition3(curr.first, curr.second, a);
        pending.emplace(curr.first, part.first);
        pending.emplace(part.second, curr.second);
    }
}


// in-place
void quick_sort(vI & a)
{
    if (a.empty()) return;

    size_t begin = 0;
    size_t end = a.size();
    sort(begin, end, a);
}


int main()
{
    // accelerating the input ======================

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);


    // read input ==================================

    Int n;
    cin >> n;

    vI arr(n);
    for (auto & item : arr)
        cin >> item;


    // display =====================================

    quick_sort(arr);
    for (const auto & item : arr)
        cout << item << " ";

    return 0;
}
