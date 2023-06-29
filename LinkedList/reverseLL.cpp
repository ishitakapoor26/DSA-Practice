#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        this->data = data;
        this->next = NULL;
    }
};
void push(Node *&head, Node *&tail, int val)
{
    Node *node1 = new Node(val);
    node1->data = val;
    if (head == NULL)
    {
        head = tail = node1;
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
void addFirst(Node *&head, int val)
{
    Node *node1 = new Node(val);
    node1->data = val;
    if (head == NULL)
    {
        head = node1;
    }
    else
    {
        node1->next = head;
        head = node1;
    }
    cout << "Pushed " << node1->data << endl;
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

// Approach 1: using vector
// Approach 2:
// void displayReverse(Node *rev)
// {
//     if (rev == NULL)
//     {
//         return;
//     }

//     displayReverse(rev->next);
//     cout << rev->data << endl;
//     // temp=temp->next;
// }

// Approach 3:

void Reverse(Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        return;
    }
    else
    {
        Reverse(head->next, tail);
        if (head == tail)
        {
            return;
        }
        else
        {
            head->next->next = head;
        }
    }
}

void displayReverse(Node *&head, Node *&tail)
{

    Reverse(head, tail);
    head->next = NULL;
    Node *temp = head;
    head = tail;
    tail = temp;
    cout<<head->data<<endl;
    cout << tail->data<<endl;
    traverse(head);
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    push(head, tail, 1);
    push(head, tail, 2);
    push(head, tail, 3);
    push(head, tail, 4);
    push(head, tail, 5);
    traverse(head);
    displayReverse(head, tail);
    return 0;
}