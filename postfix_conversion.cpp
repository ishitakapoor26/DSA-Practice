#include<iostream>
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
    Stack(int n=10)
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
            return a-b;
        }
        else if (op == '*')
        {
            // cout<<a*b<<endl;
            return a * b;
        }
        else if (op == '/')
        {
            // cout<<b/a<<endl;
            return a / b;
        }
        return -1;
    }

    int postfix_eval(char *exp){
        for(int i=0;i<size;i++){
            if(exp[i]=='+' || exp[i]=='-' || exp[i]=='/' || exp[i]=='*'){
                    if(isEmpty(1)){
                        push1(exp[i]);
                    }
                    push2(operation(pop1(),pop2(),pop2()));
                    
            }else{
                push2(int(exp[i]-'0'));
            }
        }
        if(!isEmpty(1)){
            while(!isEmpty(1) && !isEmpty(2)){
                push2(operation(pop1(),pop2(),pop2()));
            }
        }
        cout<<nd[top2]<<endl;
        return nd[top2];
    }

    string postfix_to_infix(char *exp){
        
    }
};

int main(){
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
         << st.postfix_eval(array);
    return 0;
}