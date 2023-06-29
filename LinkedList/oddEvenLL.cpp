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
    Node *head;
    Node *tail;
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }
    void push(int val)
    {
        Node *node1 = new Node(val);
        node1->data = val;
        if (this->head == NULL)
        {
            this->head = node1;
        }
        else
        {
            Node *temp = this->head;
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
        Node *temp = this->head;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    void removeHead()
    {
        head = head->next;
    }

    void oddEven()
    {
        Node *temp = head;
        int val;
        LinkedList odd, even;
        while (temp != NULL)
        {
            val = temp->data;
            this->removeHead();
            if (val % 2 == 0)
            {
                even.push(val);
            }
            else
            {
                odd.push(val);
            }
            temp = temp->next;
        }
        odd.tail->next=even.head;
        this->head=odd.head;
        this->tail=even.tail;
        this->traverse();
    }
};

int main()
{
    LinkedList list;
    list.push(1);
    list.push(9);
    list.push(7);
    list.push(11);
    list.push(5);
    list.push(13);
    list.push(19);
    list.push(3);
    list.oddEven();
    return 0;
}