#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class MedianPriorityQueue
{
public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    void push(int val)
    {
        if (size() == 0)
        {
            left.push(val);
        }
        else if (left.size() > 0 && val < left.top())
        {
            left.push(val);
        }
        else
        {
            right.push(val);
        }
        if (right.size() - left.size() == 2)
        {
            left.push(right.top());
            right.pop();
        }
        else if (left.size() - right.size() == 2)
        {
            right.push(left.top());
            left.pop();
        }
    }

    int pop()
    {
        if (size() == 0)
        {
            cout << "Underflow" << endl;
            return -1;
        }
        if (left.size() >= right.size())
        {
            int top = left.top();
            left.pop();
            return top;
        }
        else if (right.size() >= left.size())
        {
            int top = right.top();
            right.pop();
            return top;
        }
    }

    int top()
    {
        if (size() == 0)
        {
            cout << "Underflow" << endl;
            return -1;
        }
        if (left.size() >= right.size())
        {
            return left.top();
        }
        else
        {
            return right.top();
        }
    }

    int size()
    {
        return left.size() + right.size();
    }
};

int main()
{

    return 0;
}