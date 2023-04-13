#include <iostream>
using namespace std;

class Node
{
public:
    char data;
    Node *next;
    Node(char data)
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

    Node *pleft;

    bool check(Node *&head)
    {

        bool ans = true;
        if (head == NULL)
        {
            return true;
        }
        else
        {
            ans = check(head->next);
            cout << pleft->data << endl;
            if (pleft->data == head->data && ans == true)
            {
                cout << true << " " << head->data << endl;
                pleft = pleft->next;
                return true;
            }
            else
            {
                pleft = pleft->next;
                return false;
            }
        }
        if (ans)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isPalindrome(Node *&head)
    {
        pleft = head;
        if (check(head))
        {
            cout << "Palindrome" << endl;
            return true;
        }
        else
        {
            cout << "Not Palindrome" << endl;
            return false;
        }
    }
};

int main()
{
    LinkedList list;
    Node *head = NULL;
    Node *tail = NULL;
    list.push(head, tail, 'a');
    list.push(head, tail, 'n');
    list.push(head, tail, 'n');
    list.push(head, tail, 'a');
    // list.push(head, tail, 'n');
    cout << list.isPalindrome(head);
    return 0;
}