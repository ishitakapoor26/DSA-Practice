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
    void push(Node* &head, int val)
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
        }
        cout << "Pushed " << node1->data << endl;
    }
    void addFirst(Node* &head, int val)
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

    int size(Node* &head)
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

    void pop(Node* &head)
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

    void traverse(Node* &head)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    int addListHelper(Node *one, int pv1, Node *two, int pv2, Node* &res_head)
    {
        if (one == NULL && two == NULL)
        {
            return 0;
        }
        int data = 0;
        if (pv1 > pv2)
        {
            int oc = addListHelper(one->next, pv1 - 1, two, pv2, res_head);
            data = one->data + oc;
        }
        else if (pv1 < pv2)
        {
            int oc= addListHelper(one, pv1, two->next, pv2 - 1, res_head);
            data = two->data + oc;
        }
        else
        {
            int oc = addListHelper(one->next, pv1 - 1, two->next, pv2 - 1, res_head);
            data = one->data + two->data + oc;
        }
        int nd = data % 10;
        int nc = data / 10;
        addFirst(res_head, nd);
        // traverse(res_head);
        return nc;
    }

    Node* addList(Node* one, Node* two)
    {
        Node* res=NULL;
        int one_size = size(one);
        int two_size = size(two);
        int oc = addListHelper(one, one_size, two, two_size, res);
        if(oc>0){
            addFirst(res, oc);
        }
        // res.traverse();
        return res;
    }



int main()
{
    Node* head1= NULL;
    Node* head2= NULL;
    push(head1, 9);
    push(head1, 8);
    push(head1, 7);
    push(head2, 6);
    push(head2, 5);
    Node* res= addList(head1,head2);
    traverse(res);
    return 0;
}