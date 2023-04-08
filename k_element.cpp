#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
     Node(int val){
        this->data=val;
        this->next=NULL;
    }
};

class Element
{
    Node *head;

public:
    Element()
    {
        head = NULL;
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

    Node *kth_element(int k)
    {
        Node *temp = head;
        Node *ptr = head;
        for(int i=0;i<k;i++){
            ptr=ptr->next;
        }
        while(ptr!=NULL){
            ptr=ptr->next;
            temp=temp->next;
        }
        return temp;
    }
};

int main()
{
    int k;
    cin >> k;
    Element ele;
    ele.push(10);
    ele.push(20);
    ele.push(30);
    ele.push(40);
    ele.push(50);
    ele.traverse();
    Node* temp=ele.kth_element(k);
    cout<<"Answer is "<<temp->data;
    return 0;
}