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

class Stack{
    Node* head;
    public:
    Stack(){
        head=NULL;
    }

int size(){
        Node* temp=head;
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }

    void push(int val){
        Node* node1= new Node(val);
        node1->data=val;
        if(head==NULL){
            head=node1;
        }else{
            node1->next=head;
            head=node1;
        }
        cout<<"Pushed "<<node1->data<<endl;
    }

    void pop(){
        if(head==NULL){
            cout<<"List is empty"<<endl;
        }else{
            head=head->next;
        }
    }

    int top(){
        return head->data;
    }

    void traverse(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<endl;
            temp=temp->next;
        }
    }
};


int main(){
    Stack n;
    n.push(10);
    n.push(12);
    n.push(14);
    n.traverse();
    n.pop();
    cout<<n.size();
    n.traverse();
    return 0;
}