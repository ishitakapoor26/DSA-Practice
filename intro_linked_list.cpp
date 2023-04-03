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

int size(Node *&head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

void insertAtLast(Node *&tail, int num)
{
    Node *temp = new Node(num);
    tail->next = temp;
    temp->next = NULL;
    tail = temp;
}

void InsertAtHead(Node *&head, int d)
{
    if (size(head) == 0)
    {
        head->data = d;
        head->next = NULL;
    }
    else
    {
        Node *temp = new Node(d);
        temp->next = head;
        head = temp;
    }
}

void traverse(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

void insertAtIndex(Node *&head, int index, int val)
{
    if (size(head) == 0)
    {
        head->data = val;
        head->next = NULL;
    }
    else if (index == 1)
    {
        InsertAtHead(head, val);
    }
    else
    {
        Node *temp = new Node(val);
        Node *ptr = head;
        for (int i = 0; i < index - 2; i++)
        {
            ptr = ptr->next;
        }
        temp->next = ptr->next;
        ptr->next = temp;
    }
}

int getFirst(Node *&head)
{
    if (size(head) == 0)
    {
        return -1;
    }
    else
    {
        return head->data;
    }
}

int getLast(Node *&head, Node *&tail)
{
    if (size(head) == 0)
    {
        return -1;
    }
    else
    {
        return tail->data;
    }
}

int getValue(Node *&head, int index)
{
    Node *temp = head;
    if (size(head) == 0)
    {
        return -1;
    }
    else if (index < 0 || index >= size(head))
    {
        return -1;
    }
    for (int i = 0; i < index; i++)
    {
        if (i == index - 1)
        {
            return temp->data;
        }
        else
        {
            temp = temp->next;
        }
    }
    return -1;
}

void remove_first(Node* &head)
{
    head = head->next;
}

void remove_last(Node* &head, Node* &tail)
{
    if (size(head) == 0)
    {
        cout << "List is empty" << endl;
    }
    else if (size(head) == 1)
    {
        head = tail = NULL;
    }
    else
    {
        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        tail = temp;
    }
}

void removeAt(Node* &head, int index, Node* &tail){
    Node* temp=head;
    if (size(head) == 0)
    {
        cout << "List is empty" << endl;
    }
    else if (size(head) == 1)
    {
        head = tail = NULL;
    }else if(index==size(head)){
        remove_last(head,tail);
    }
    else{
        for(int i=0;i<index-2;i++){
            temp=temp->next;
        }
        temp->next=temp->next->next;
    }
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    insertAtLast(tail, 12);
    insertAtLast(tail, 14);
    insertAtLast(tail, 15);
    traverse(head);
    cout<<"------------"<<endl;
    // cout << "Remove from beginning" << endl;
    // remove_first(head);
    // traverse(head);
    // cout << "First element is " << getFirst(head) << endl;
    // cout << "Last element is " << getLast(head, tail) << endl;
    // cout << "Element at 2 index is " << getValue(head, 2);
    // cout<<size(head);
    insertAtIndex(head, 1, 10);
    traverse(head);
    cout<<"------------"<<endl;
    remove_last(head, tail);
    traverse(head);
    return 0;
}