#include <iostream>
#include <stack>
using namespace std;
using Int = int32_t;


template <typename T>
class Stack
{
private:

    stack<T> stack_;
    stack<T> max_;

public:

    void push(T input)
    {
        if (stack_.empty())
        {
            stack_.push(input);
            max_.push(input);
            return;
        }

        if (input >= max_.top())
        {
            max_.push(input);
            stack_.push(input);
        }
        else
            stack_.push(input);
    }

    void pop()
    {
        if (stack_.top() == max_.top())
        {
            stack_.pop();
            max_.pop();
            return;
        }

        stack_.pop();
    }

    bool empty() const { return stack_.empty(); }
    T top() const { return stack_.top(); }
    T max() const { return max_.top(); }
};


int main()
{
    // accelerating the input ======================

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    // read input ==================================
    // display =====================================

    Int queries;
    cin >> queries;

    string cmd;
    Int n;

    Stack<Int> stack;

    for (int i = 0; i < queries; ++i)
    {
        cin >> cmd;

        if (cmd == "push")
        {
            cin >> n;
            stack.push(n);
            continue;
        }

        if (cmd == "pop")
        {
            stack.pop();
            continue;
        }

        if (cmd == "max")
        {
            cout << stack.max() << endl;
            continue;
        }
        
        throw runtime_error("wrong command: " + cmd);
    }

    return 0;
}
