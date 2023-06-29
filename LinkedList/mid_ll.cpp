#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList
{
    Node *head;
    Node *tail;

public:
    LinkedList()
    {
        head = NULL;
    }
    void push(int val)
    {
        Node *node1 = new Node(val);
        node1->data = val;
        if (head == NULL)
        {
            head = node1;
            tail=node1;
        }
        else
        {
            node1->next = head;
            head = node1;
        }
        cout << "Pushed " << node1->data << endl;
    }

    void pop()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            head = head->next;
        }
    }

    void traverse()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }

        // cout<<"Head is"<<head->data<<endl;
        // cout<<"Tail is "<<tail->data<<endl;
    }

    void mid_list(){
        Node* s=head;
        Node* f=head;
        while(f->next!=NULL && f->next->next!=NULL){
           f=f->next->next;
           s=s->next;
        }
        cout<<"Middle element is "<<s->data;
    }
};

int main()
{
    LinkedList list;
    list.push(10);
    list.push(20);
    list.push(30);
    // list.push(40);
    list.traverse();
    list.mid_list();
    // Node* ans= list.mid_list();
    // cout<<"Middle element of list is "<<ans->data;
    return 0;
}