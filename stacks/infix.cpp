#include <iostream>
using namespace std;

class Stack
{
private:
    int top1;
    int top2;
    int size;
    char *op{new char[size]};
    int *nd{new int[size]};

public:
    Stack(int n)
    {
        top1 = top2 = -1;
        size = n;
    }

    bool isEmpty(int choice)
    {
        if (top1 == -1 && choice == 1)
        {
            // cout << "Stack is Empty" << endl;
            return true;
        }
        else if (top2 == -1 && choice == 2)
        {
            // cout << "Stack is Empty" << endl;
            return true;
        }
        return false;
    }

    bool isFull()
    {
        if (top1 == size - 1)
        {
            cout << "Stack is full" << endl;
            return true;
        }
        else if (top2 == size - 1)
        {
            cout << "Stack is full" << endl;
            return true;
        }
        return false;
    }

    void push1(char x)
    {
        if (isFull())
        {
            return;
        }
        cout << "Stack 1 pushed " << x << endl;
        top1++;
        op[top1] = x;
    }

    void push2(int x)
    {
        if (isFull())
        {
            return;
        }
        cout << "Stack 2 pushed " << x << endl;
        top2++;
        nd[top2] = x;
    }

    char pop1()
    {
        char ch;
        if (isEmpty(1))
        {
            return ' ';
        }
        ch = op[top1];
        cout << "Stack 1 Pops " << ch << endl;
        top1--;
        return ch;
    }

    int pop2()
    {
        int x;
        if (isEmpty(2))
        {
            return -1;
        }
        x = nd[top2];
        cout << "Stack 2 Pops " << x << endl;
        top2--;
        return x;
    }

    int precedence(char ch)
    {
        if (ch == '+')
        {
            return 1;
        }
        else if (ch == '-')
        {
            return 1;
        }
        else if (ch == '*')
        {
            return 2;
        }
        else if (ch == '/')
        {
            return 2;
        }
        return 0;
    }

    int operation(char op, int a, int b)
    {
        cout<<"a is "<<a<<endl;
        cout<<"b is "<<b<<endl;
        if (op == '+')
        {
            // cout<<a+b<<endl;
            cout<<a+b<<endl;
            return a + b;
        }
        else if (op == '-')
        {
            // cout<<b-a<<endl;
            return b - a;
        }
        else if (op == '*')
        {
            // cout<<a*b<<endl;
            return a * b;
        }
        else if (op == '/')
        {
            // cout<<b/a<<endl;
            return b / a;
        }
        return -1;
    }

    int infix(char *str)
    {
        int a,b,c;
        for (int i = 0; i < size; i++)
        {
            if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*' || str[i] == '(' || str[i] == ')')
            {
                if (isEmpty(1) || str[i] == '(' || precedence(op[top1]) < precedence(str[i]))
                {
                    cout << str[i] << endl;
                    push1(str[i]);
                }
                else
                {
                    if (str[i] == ')')
                    {
                        while (op[top1] != '(' && !isEmpty(1))
                        {
                            a=pop2();
                            cout<<"a"<<endl;
                            b=pop2();
                            cout<<b<<endl;
                            push2(operation(pop1(), a, b));
                        }
                        if (!isEmpty(1))
                        {
                            pop1();
                        }
                    }
                    else if (precedence(op[top1]) >= precedence(str[i]))
                    {
                        a=pop2();
                        b=pop2();
                        push2(operation(pop1(), a, b));
                        if (!isEmpty(1))
                        {
                            pop1();
                        }
                        push1(str[i]);
                    }
                }
            }
            else
            {
                c= int(str[i]-'0');
                cout<<c<<endl;
                push2(c);
            }
        }
        if (!isEmpty(1)){    
        while(!isEmpty(1) && !isEmpty(2)){
            a=pop2();
            b=pop2();
            push2(operation(pop1(), a, b));
        }
        }
        return nd[top2];
    }
};

int main()
{
    string exp;
    cin >> exp;
    cout << exp.length() << endl;
    Stack st(exp.length());
    char *array = new char[exp.length()];
    for (int i = 0; i < exp.length(); i++)
    {
        array[i] = exp[i];
    }
    cout << array << endl
         << st.infix(array);
    return 0;
}