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
            tail=node1;
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

    Node *mid(Node *head, Node *tail)
    {
        Node *s = head;
        Node *f = head;
        while (f->next != tail && f->next->next != tail)
        {
            f = f->next->next;
            s = s->next;
        }
        return s;
    }

    LinkedList merge_list(LinkedList l1, LinkedList l2)
    {
        Node *head1 = l1.head;
        Node *head2 = l2.head;
        LinkedList l3;
        while (head1 != NULL && head2 != NULL)
        {
            if (head1->data <= head2->data)
            {
                l3.push(head1->data);
                head1 = head1->next;
            }
            else
            {
                l3.push(head2->data);
                head2 = head2->next;
            }
        }
        while (head1 != NULL)
        {
            l3.push(head1->data);
            head1 = head1->next;
        }
        while (head2 != NULL)
        {
            l3.push(head2->data);
            head2 = head2->next;
        }
        l3.traverse();
        return l3;
    }

    LinkedList merge_sort(Node *head, Node *tail)
    {
        if (head == tail)
        {
            LinkedList br;
            br.push(head->data);
            return br;
        }
        Node *middle = mid(head, tail);
        LinkedList fsh, ssh,cl;
        fsh.merge_sort(head, middle);
        ssh.merge_sort(middle->next,tail);
        cl.merge_list(fsh, ssh);
        // cl.traverse();
        return cl;
    }
};

int main()
{
    LinkedList list,cl;
    list.push(10);
    list.push(2);
    list.push(19);
    list.push(22);
    list.push(3);
    list.push(7);
    cout<<list.head->data<<endl;
    cout<<list.tail->data<<endl;
    cl=list.merge_sort(list.head,list.tail);
    // cl.traverse();
    return 0;
}