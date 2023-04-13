#include <iostream>
#include <stack>
using namespace std;

// This add efficicent, i.e. adding with TC O(1)

class Queue
{
    stack<int> st1, st2;

public:
    void add(int val)
    {
        st1.push(val);
    }

    void remove()
    {
        while (st1.size() > 1)
        {
            st2.push(st1.top());
            st1.pop();
        }
        st1.pop();
        while (!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
    }

    int peek()
    {
        while (!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        int val = st2.top();
        while (!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
        return val;
    }

    int size()
    {
        return st1.size();
    }

    void display()
    {
        stack<int> st = st1;
        for (int i = st.size() - 1; i >= 0; i--)
        {
            cout << st.top() << endl;
            st.pop();
        }
    }
};

int main()
{
    Queue q;
    q.add(1);
    q.add(2);
    q.add(3);
    q.display();
    q.remove();
    q.display();
    q.add(4);
    q.add(5);
    q.display();
    return 0;
}