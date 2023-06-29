#include <iostream>
using namespace std;

class Stack
{
private:
    int pre_top;
    int post_top;
    int size;
    string *pre{new string[50]};
    string *post{new string[50]};
    string *op{new string[50]};
    int op_top;

public:
    Stack(int n)
    {
        size = n;
        pre_top = -1;
        post_top = -1;
        op_top = -1;
    }

    bool isFull(int choice)
    {
        switch (choice)
        {
        case 1:
            if (pre_top == size - 1)
            {
                cout<<"Prefix stack is full"<<endl;
                return true;
            }
            return false;
            break;
        case 2:
            if (post_top == size - 1)
            {
                 cout<<"Postfix stack is full"<<endl;
                return true;
            }
            return false;
            break;
        case 3:
            if (op_top == size - 1)
            {
                 cout<<"Operator stack is full"<<endl;
                return true;
            }
            return false;
            break;
        }
        return false;
    }

    bool isEmpty(int choice)
    {
        switch (choice)
        {
        case 1:
            if (pre_top == -1)
            {
                cout<<"Pefix stack is empty"<<endl;
                return true;
            }
            return false;
            break;
        case 2:
            if (post_top == -1)
            {
                cout<<"Postfix stack is empty"<<endl;
                return true;
            }
            return false;
            break;
        case 3:
            if (op_top == -1)
            {
                cout<<"Operator stack is empty"<<endl;
                return true;
            }
            return false;
            break;
        }
        return false;
    }

    int precedence(string ch)
    {
        if (ch == "+" || ch == "-")
        {
            return 1;
        }
        else if (ch == "*" || ch == "/")
        {
            return 2;
        }
        return -1;
    }

    string operation(string op, string ch1, string ch2, int choice)
    {
        if (choice == 1)
        {
            return op + ch1 + ch2;
        }
        else if (choice == 2)
        {
            return ch1 + ch2 + op;
        }
        return " ";
    }

    void push_pre(string ch)
    {
        if (isFull(1))
        {
            return;
        }
        cout << "Prefix stack pushed " << ch << endl;
        pre_top++;
        pre[pre_top] = ch;
    }

    void push_post(string ch)
    {
        if (isFull(2))
        {
            return;
        }
        cout << "Postfix stack pushed " << ch << endl;
        post_top++;
        post[post_top] = ch;
    }

    void push_op(string ch)
    {
        if (isFull(3))
        {
            return;
        }
        cout << "Operator stack pushed " << ch << endl;
        op_top++;
        op[op_top] = ch;
    }

    string pop_pre()
    {
        string ch;
        if (isEmpty(1))
        {
            return " ";
        }
        ch = pre[pre_top];
        cout << "Prefix stack popped " << ch << endl;
        pre_top--;
        return ch;
    }

    string pop_post()
    {
        string ch;
        if (isEmpty(2))
        {
            return " ";
        }
        ch = post[post_top];
        cout << "Postfix stack popped " << ch << endl;
        post_top--;
        return ch;
    }

    string pop_op()
    {
        string ch;
        if (isEmpty(3))
        {
            return " ";
        }
        ch = op[op_top];
        cout << "Operator stack popped " << ch << endl;
        op_top--;
        return ch;
    }

    void infix_to_prefix(string *exp)
    {
        string ch = "";
        for (int i = 0; i < size; i++)
        {
            ch = exp[i];
            if (ch == "+" || ch == "-" || ch == "*" || ch == "/" || ch == "(" || ch == ")")
            {
                if (isEmpty(3) || precedence(ch) > precedence(op[op_top]) || ch == "(")
                {
                    push_op(ch);
                }
                else
                {
                    if (ch == ")")
                    {
                        while (op[op_top] != "(")
                        {
                            push_pre(operation(pop_op(), pop_pre(), pop_pre(), 1));
                        }
                        if(!isEmpty(3)){
                        pop_op();
                        }
                    }
                    else if (precedence(ch) <= precedence(op[op_top]))
                    {
                        push_pre(operation(pop_op(), pop_pre(), pop_pre(), 1));
                        push_op(ch);
                    }
                }
            }
            else
            {
                push_pre(ch);
            }
        }
        if (!isEmpty(1) && !isEmpty(3))
        {
            while (!isEmpty(3))
            {
                push_pre(operation(pop_op(), pop_pre(), pop_pre(), 1));
            }
        }
        cout << "Prefix expression is "<<pre[pre_top]<<endl;
    }

    void infix_postfix(string *exp){
        string ch = "";
        for (int i = 0; i < size; i++)
        {
            ch = exp[i];
            if (ch == "+" || ch == "-" || ch == "*" || ch == "/" || ch == "(" || ch == ")")
            {
                if (isEmpty(3) || precedence(ch) > precedence(op[op_top]) || ch == "(")
                {
                    push_op(ch);
                }
                else
                {
                    if (ch == ")")
                    {
                        while (op[op_top] != "(")
                        {
                            push_post(operation(pop_op(), pop_post(), pop_post(), 2));
                        }
                        if(!isEmpty(3)){
                        pop_op();
                        }
                    }
                    else if (precedence(ch) <= precedence(op[op_top]))
                    {
                        push_post(operation(pop_op(), pop_post(), pop_post(), 2));
                        push_op(ch);
                    }
                }
            }
            else
            {
                push_post(ch);
            }
        }
        if (!isEmpty(2) && !isEmpty(3))
        {
            while (!isEmpty(3))
            {
                push_post(operation(pop_op(), pop_post(), pop_post(), 2));
            }
        }
        cout << "Postfix expression is "<<post[post_top]<<endl;
    }
    };

int main()
{
    string exp;
    cin >> exp;
    string *arr= new string[exp.length()];
    for(int i=0;i<exp.length();i++){
        arr[i]=exp[i];
        cout<<arr[i]<<endl;
    }
    Stack st(exp.length());
    st.infix_to_prefix(arr);
    st.infix_postfix(arr);
    return 0;
}