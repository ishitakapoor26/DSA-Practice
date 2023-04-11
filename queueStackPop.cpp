#include <iostream>
using namespace std;
#include<queue>

class Stack
{

queue<int> main, helper;

public:

    void push(int val)
    {
    //    Queue main(10), helper(10);
       while(!main.empty()){
        helper.push(main.front());
        main.pop();
       }
       main.push(val);
       while(!helper.empty()){
        main.push(helper.front());
        helper.pop();
       }

    }

    void pop()
    {
        if (main.empty())
            return;
        main.pop();
    }

    void display(){
        queue<int> q=main;
        while(!q.empty()){
            cout<<q.front()<<endl;
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
    st.push(6);
    st.push(7);
    st.display();
    return 0;
}