#include <iostream>
#include<string>
using namespace std;

class Stack
{
private:
    int pre_top;
    int op_top;
    int size;
    string *pre{new string[10]};
    string *op{new string[10]};

public:
    Stack(int n)
    {
        pre_top = op_top = -1;
        size = n;
    }

    bool isEmpty(int choice)
    {
        if (choice == 1)
        {
            if (pre_top == -1)
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
            if (pre_top == size - 1)
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
            cout << "prefix stack pushed " << str << endl;
            pre_top++;
            pre[pre_top] = str;
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
            string ch = pre[pre_top];
            cout << "prefix stack popped " << ch << endl;
            pre_top--;
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
            cout << "prefix stack popped " << ch << endl;
            op_top--;
            return ch;
        }
    }

    string operation(string op, string a, string b, int choice)
    {
        if(choice==1){
        return "(" + b + op + a + ")";
        }else if(choice ==2){
            return b+a+op;
        }
        return " ";
    }

    string pre_to_infix(string *exp)
    {
        string ch = "";
        for (int i = size - 1; i >= 0; i--)
        {
            ch = exp[i];
            if (exp[i] == "+" || exp[i] == "-" || exp[i] == "*" || exp[i] == "/")
            {
                push_op(ch);
                push_nd(operation(pop_op(), pop_nd(), pop_nd(),1));
            }
            else
            {
                push_nd(ch);
            }
        }
        cout << pre[pre_top] << endl;
        return pre[pre_top];
    }

    int algebra(string op, string a, string b){
        if(op=="+"){
            return stoi(b)+stoi(a);
        }else if(op=="-"){
            return stoi(b)-stoi(a);
        }else if(op=="*"){
            return stoi(b)*stoi(a);
        }else if(op=="/"){
            return stoi(b)/stoi(a);
        }
        return 0;
    }

    string prefix_eval(string *exp)
    {
        string ch = "";
        for (int i = size - 1; i >= 0; i--)
        {
            ch = exp[i];
            if (exp[i] == "+" || exp[i] == "-" || exp[i] == "*" || exp[i] == "/")
            {
                push_op(ch);
                push_nd(to_string(algebra(pop_op(), pop_nd(), pop_nd())));
            }
            else
            {
                push_nd(ch);
            }
        }
        cout << pre[pre_top] << endl;
        return pre[pre_top];
    }

    string pre_to_post(string *exp){
        string ch = "";
        for (int i = size - 1; i >= 0; i--)
        {
            ch = exp[i];
            if (exp[i] == "+" || exp[i] == "-" || exp[i] == "*" || exp[i] == "/")
            {
                push_op(ch);
                push_nd(operation(pop_op(), pop_nd(), pop_nd(),2));
            }
            else
            {
                push_nd(ch);
            }
        }
        cout << pre[pre_top] << endl;
        return pre[pre_top];
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
    // st.pre_to_infix(arr);
    // st.prefix_eval(arr);
    st.pre_to_post(arr);
    return 0;
}