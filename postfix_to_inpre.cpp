#include <iostream>
using namespace std;

class Stack
{
private:
    int post_top;
    int op_top;
    int size;
    string *post{new string[size + 2]};
    string *op{new string[size + 2]};

public:
    Stack(int n)
    {
        post_top = op_top = -1;
        size = n;
    }

    bool isEmpty(int choice)
    {
        if (choice == 1)
        {
            if (post_top == -1)
            {
                return true;
            }
            else if (choice == 2)
            {
                if (op_top == -1)
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool isFull(int choice)
    {
        if (choice == 1)
        {
            if (post_top == size - 1)
            {
                return true;
            }
            else if (choice == 2)
            {
                if (op_top == size - 1)
                {
                    return true;
                }
            }
        }
        return false;
    }

    void push_nd(string str)
    {
        if (isFull(1))
        {
            return;
        }
        else
        {
            cout << "Postfix stack pushed " << str << endl;
            post_top++;
            post[post_top] = str;
        }
    }

    string pop_nd()
    {
        if (isEmpty(1))
        {
            return " ";
        }
        else
        {
            string ch = post[post_top];
            cout << "Postfix stack popped " << ch << endl;
            post_top--;
            return ch;
        }
    }

    void push_op(string ch)
    {
        if (isFull(2))
        {
            return;
        }
        else
        {
            op_top++;
            op[op_top] = ch;
            cout << "Operator stack pushed " << ch << endl;
        }
    }

    string pop_op()
    {
        if (isEmpty(2))
        {
            return " ";
        }
        else
        {
            string ch = op[op_top];
            cout << "Postfix stack popped " << ch << endl;
            op_top--;
            return ch;
        }
    }

    string operation(string op, string a, string b, int choice)
    {
        if (choice == 1)
        {
            return "(" + a + op + b + ")";
        }
        else if (choice == 2)
        {
            return op + a + b;
        }
        return " ";
    }

    string post_to_infix(string *exp)
    {
        string ch = "";
        for (int i = 0; i < size; i++)
        {
            ch = exp[i];
            if (exp[i] == "+" || exp[i] == "-" || exp[i] == "*" || exp[i] == "/")
            {

                push_op(ch);
                push_nd(operation(pop_op(), pop_nd(), pop_nd(), 1));
            }
            else
            {
                push_nd(ch);
            }
        }
        cout << post[post_top] << endl;
        return post[post_top];
    }

    string post_to_prefix(string *exp)
    {
        string ch = "";
        for (int i = 0; i < size; i++)
        {
            ch = exp[i];
            if (exp[i] == "+" || exp[i] == "-" || exp[i] == "*" || exp[i] == "/")
            {

                push_op(ch);
                push_nd(operation(pop_op(), pop_nd(), pop_nd(), 2));
            }
            else
            {
                push_nd(ch);
            }
        }
        cout << post[post_top] << endl;
        return post[post_top];
    }
};

int main()
{
    string exp;
    cin >> exp;
    string *arr = new string[exp.length()];
    for (int i = 0; i < exp.length(); i++)
    {
        arr[i] = exp[i];
        cout << arr[i] << endl;
    }
    Stack st(exp.length());
    cout << st.post_to_infix(arr) << endl;
    cout << st.post_to_prefix(arr) << endl;
    return 0;
}