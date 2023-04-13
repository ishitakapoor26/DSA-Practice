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

public:
    void push(Node *&head, Node *&tail, int val)
    {
        Node *node1 = new Node(val);
        node1->data = val;
        if (head == NULL)
        {
            head = node1;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = node1;
            node1->next = NULL;
            tail = node1;
        }
        cout << "Pushed " << node1->data << endl;
    }

    void pop(Node *&head)
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

    void traverse(Node *&head)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    int intersectionLL(Node *&head1, Node *&head2)
    {
        // int n1 = size(head1);
        // cout<<n1<<endl;
        // int n2 = size(head2);
        Node *temp = head1;
        cout << head1->data << endl;
        Node *ptr = head2;
        cout << head2->data << endl;
            for (int i = 0; i < 1; i++)
            {
                temp = temp->next;
            }
        
        while (temp->next != NULL && ptr->next!=NULL)
        {
            if(temp==ptr){
                return temp->data;
            }
            temp = temp->next;
            cout<<temp->data<<endl;
            ptr = ptr->next;
            cout<<ptr->data<<endl;
        }
        return -1;
    }

    int size(Node *&head)
    {
        Node *temp = head;
        int count = 0;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main()
{
    LinkedList l1, l2;
    Node *head1 = NULL;
    Node *head2 = NULL;
    Node *tail1 = NULL;
    Node *tail2 = NULL;
    l1.push(head1, tail1, 1);
    l1.push(head1, tail1, 2);
    l1.push(head1, tail1, 3);
    l1.push(head1, tail1, 4);
    l1.push(head2, tail2, 5);
    l1.push(head2, tail2, 6);
    l2.push(head2, tail2, 9);
    l2.push(head2, tail2, 8);
    l2.push(head2, tail2, 4);
    l2.push(head2, tail2, 5);
    l2.push(head2, tail2, 6);
    // l2.push(head2, tail2, 4);
    cout << "Intersection Node Data is: " << l1.intersectionLL(head1, head2)<<endl;
    return 0;
}