#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        this->data=val;
        this->next=NULL;
    }
};

class Queue{
    private:
    Node* top;
    public:

    Queue(){
        top=NULL;
    }

    void push(int val){
        Node* temp=top;
        Node* t= new Node(val);
        if(top==NULL){
            top=t;
        }else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=t;
        }
    }

    void pop(){
        if(top==NULL){
            cout<<"List is empty"<<endl;
        }else{
            top=top->next;
        }
    }

    void traverse(){
        Node* temp=top;
        while(temp!=NULL){
            cout<<temp->data<<endl;
            temp=temp->next;
        }
    }
};

int main(){
    Queue q;
    q.push(10);
    q.push(12);
    q.push(14);
    q.traverse();
    q.pop();
    q.traverse();
    return 0;
}