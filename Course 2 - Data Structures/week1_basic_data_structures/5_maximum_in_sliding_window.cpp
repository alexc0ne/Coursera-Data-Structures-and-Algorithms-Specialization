#include <iostream>
#include <stack>
#include <vector>
using namespace std;
using Int = int32_t;
using vI = vector<Int>;


// Stack =======================================
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


// Queue =======================================
template <typename T>
class Queue
{
private:

    Stack<T> in_;
    Stack<T> out_;
    size_t size_;

    void pour(Stack<T> & from, Stack<T> & to)
    {
        while (!from.empty())
        {
            to.push(from.top());
            from.pop();
        }
    }


public:

    Queue() : size_(0) {}

    void enqueue(T n)
    {
        in_.push(n);
        ++size_;
    }

    void dequeue()
    {
        if (out_.empty())
            pour(in_, out_); // from in_ into out_

        out_.pop();
        --size_;
    }

    size_t size() const { return size_; }

    T max() const
    {
        if (in_.empty() and out_.empty())
            throw runtime_error("Getting max value from empty queue.");

        if (in_.empty()) return out_.max();
        if (out_.empty()) return in_.max();

        return ::max(in_.max(), out_.max());
    }
};


int main()
{
    // accelerating the input ======================

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    // read input ==================================
    // display =====================================
    Int n;
    cin >> n;

    vI v(n);
    for (auto & item : v)
        cin >> item;

    Int k;
    cin >> k;

    Queue<Int> queue;
    for (Int i = 0; i < k; ++i)
        queue.enqueue(v[i]);

    cout << queue.max() << " ";

    for (Int i = k; i < n; ++i)
    {
        queue.dequeue();
        queue.enqueue(v[i]);
        cout << queue.max() << " ";
    }

    return 0;
}
