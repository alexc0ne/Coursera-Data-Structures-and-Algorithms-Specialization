#include <iostream>
#include <vector>
using namespace std;
using Int = int32_t;
using vI = vector<Int>;


int main()
{
    Int W, n;
    cin >> W >> n;

    vI bar(n);
    for (auto & item : bar)
        cin >> item;

    // вектор весов от 0 до W (индексы)
    vI w(W + 1);

    // 0 слитков мы можем взять одним способом
    w[0] = 1;

    Int j;
    Int current_bar;
    
    // пробегаем по слиткам
    for (Int i = 0; i < n; ++i)
    {
        j = W;
        current_bar = bar[i];
        
        // далее идем по сути справа налево и, как только встречаем 1 в векторе w
        // (в индексе j - current_bar), то к этому индексу прибавляем current_bar (масса слитка),
        // что говорит о том, что мы можем набрать массу j из слитка current_bar и слитка/слитков, что
        // даёт/дают массу в j - current_bar
        while (j - current_bar >= 0)
        {
            if (w[j - current_bar] == 1)
                w[j] = 1;

            --j;
        }
    }

    for (Int i = W; i >= 0; --i)
        if (w[i] == 1)
        {
            cout << i;
            break;
        }

    return 0;
}
