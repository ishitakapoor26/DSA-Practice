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

    void addFirst(int val)
    {
        Node *node1 = new Node(val);
        node1->data = val;
        if (this->head == NULL)
        {
            this->head = node1;
            this->tail= node1;
        }
        else
        {
            node1->next = head;
            head = node1;
        }
        cout << "Pushed " << node1->data << endl;
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
            tail=node1;
        }
        cout << "Pushed " << node1->data << endl;
    }

    int size()
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

    int getFirst()
    {
        return head->data;
    }

    void removeFirst()
    {
        head = head->next;
    }

    void kReverse(int k)
    {
       LinkedList prev;
        while (this->size() > 0)
        {
            LinkedList curr;
            if (this->size() >= k)
            {
                for (int i = 0; i < k; i++)
                {
                    int val = this->getFirst();
                    this->removeFirst();
                    curr.addFirst(val);
                }
            }
            else
            {
                int os = this->size();
                for (int i = 0; i < os; i++)
                {
                    int val = this->getFirst();
                    this->removeFirst();
                    curr.push(val);
                }
            }
            curr.traverse();
            cout<<prev.head<<endl;
            if (prev.size()==0)
            {
                prev = curr;
            }
            else
            {
                prev.tail->next = curr.head;
                prev.tail = curr.tail;
            }
        }
        prev.traverse();
        // this->head = prev.head;
        // this->tail = prev.tail;
    }
};

int main()
{
    LinkedList list;
    int k;
    cin >> k;
    list.push(1);
    list.push(2);
    list.push(3);
    list.push(8);
    list.push(9);
    list.push(10);
    // list.push();
    list.kReverse(k);
    list.traverse();
}