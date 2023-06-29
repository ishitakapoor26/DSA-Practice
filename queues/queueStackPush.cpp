#include <iostream>
#include <queue>
using namespace std;

class Stack
{
    queue<int> q1, q2;

public:
    void push(int val)
    {
        q1.push(val);
    }
    void pop()
    {
        while (q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        while (q2.size() > 0)
        {
            q1.push(q2.front());
            q2.pop();
        }
    }

    int size()
    {
        return q1.size();
    }

    // int top()
    // {
    //     return q1.back();
    // }

    void display()
    {
        queue<int> q = q1;
        while (!q.empty())
        {
            cout << q.front() << endl;
            q.pop();
        }
    }
};

int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.display();
    st.pop();
    st.display();
    st.pop();
    st.display();
    return 0;
}