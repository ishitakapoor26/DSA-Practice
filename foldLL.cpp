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

    Node *fleft;
    int n;
    void fLinkedList(Node *head, int floor, Node *tail)
    {
        if (head == NULL)
        {
            return;
        }
        else
        {
            fLinkedList(head->next, floor + 1, tail);
            if (floor > n / 2)
            {
                Node *temp = fleft->next;
                head->next = temp;
                fleft->next = head;
                fleft = temp;
            }
            else if (floor == n / 2)
            {
                tail = head;
                tail->next = NULL;
            }
        }
    }

    void foldLL(Node *&head, Node *&tail)
    {
        fleft = head;
        n = size(head);
        Node *res;
        fLinkedList(head, 0, tail);
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
    LinkedList list;
    Node *head = NULL;
    Node *tail = NULL;
    list.push(head, tail, 1);
    list.push(head, tail, 2);
    list.push(head, tail, 3);
    list.push(head, tail, 4);
    list.push(head, tail, 5);
    // list.push(head, tail, 6);
    list.foldLL(head, tail);
    list.traverse(head);
    return 0;
}