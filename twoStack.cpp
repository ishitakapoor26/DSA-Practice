#include <iostream>

using namespace std;

class twoStack
{
private:
    int top1, top2;
    int *arr{new int[10]};
    int size = 10;

public:
    twoStack()
    {
        top1 = -1;
        top2 = size - 1;
        ;
    }

    int size1()
    {
        return top1 + 1;
    }

    void push1(int val)
    {
        if (top2 == top1 + 1)
        {
            return;
        }
        else
        {
            top1++;
            arr[top1] = val;
        }
    }

    void pop1()
    {
        if (top1 == -1)
            return;
        top1--;
    }

    int size2()
    {
        return size - top1;
    }

    void push2(int val)
    {
        if (top2 == top1 + 1)
        {
            return;
        }
        else
        {
            top2--;
            arr[top2] = val;
        }
    }

    void pop2()
    {
        if (top2 == size - 1)
            return;
        top2++;
    }
};

int main()
{
    return 0;
}