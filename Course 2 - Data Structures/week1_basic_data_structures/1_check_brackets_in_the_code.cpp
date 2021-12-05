#include <iostream>
#include <stack>
using namespace std;


const string opening{"([{"};
const string closing{")]}"};


bool BelongsTo(const string & chars, char ch)
{
    for (auto item : chars)
        if (ch == item)
            return true;

    return false;
}


bool IsPair(char left, char right)
{
    return abs(left - right) <= 2;
}


string CheckBrackets(const string & seq)
{
    stack<char> st;
    stack<size_t> index; // this stack contains indices of opening brackets
    size_t idx = 1;

    for (auto ch : seq)
    {
        // not a bracket symbol
        if (!BelongsTo(opening, ch) and !BelongsTo(closing, ch))
        {
            ++idx;
            continue;
        }

        if (BelongsTo(opening, ch))
        {
            st.push(ch);
            index.push(idx);
            ++idx;
            continue;
        }

        //   ), ] or }
        if (st.empty()) return to_string(idx);
        else // stack is not empty
        {
            if (IsPair(st.top(), ch))
            {
                st.pop();
                index.pop();
                ++idx;
            }
            else return to_string(idx); // unpaired brackets
        }
    }

    if (st.empty()) return "Success";
    return to_string(index.top());

}



int main()
{
    // accelerating the input ======================

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    // read input ==================================

    string s;
    cin >> s;


    // display =====================================
    
    cout << CheckBrackets(s);


    return 0;
}
