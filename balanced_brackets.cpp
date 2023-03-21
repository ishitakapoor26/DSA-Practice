#include <iostream>
using namespace std;

class Stack
{
public:
    int top;
    int size;
    char *arr{new char[size]};

public:
    Stack(int strlen)
    {
        size = strlen;
        top = -1;
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            // cout << "Stack is empty" << endl;
            return true;
        }
        return false;
    }

    bool isFull()
    {
        if (top == size - 1)
        {
            // cout << "Stack is full" << endl;
            return true;
        }
        return false;
    }

    void push(char ch)
    {
        if (isFull())
        {
            // cout << "Stack Overflow" << endl;
            return;
        }
        else
        {
            top++;
            arr[top] = ch;
        }
    }

    void pop()
    {
        char ch;
        if (isEmpty())
        {
            // cout << "Stack Underflow" << endl;
            return;
        }
        else
        {
            top--;
        }
    }

    bool balanced_brackets(string str)
    {
       
        for (int i = 0; i < size; i++)
        {
            if(str[i]=='(' || str[i]=='[' || str[i]=='{'){
                push(str[i]);
            }else if(str[i]==')' || str[i]==']' || str[i]=='}'){
                if(str[i]==']' && arr[top]=='['){
                    if(!isEmpty()){
                        pop();
                    }
                }else if(str[i]=='}' && arr[top]=='{'){
                    if(!isEmpty()){
                        pop();
                    }
                }else if(str[i]==')' && arr[top]=='('){
                    if(!isEmpty()){
                        pop();
                    }
            }else{
                return false;
            }
                }
        }
            if(isEmpty()){
                return true;
            }else{
                return false;
            }

    }
};

int main()
{
    string str;
    cout << "Enter the expression:" << endl;
    cin >> str;
    Stack st = Stack(str.length());
    if (st.balanced_brackets(str))
    {
        cout << "Brackets are Balanced";
    }
    else
    {
        cout << "Brackets Unbalanced";
    }
    return 0;
}