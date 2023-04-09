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

// Approach 1 : TC: O(n) SP: O(n)
    // void removeDuplicates()
    // {
    //     Node *temp = head;
    //     LinkedList ans;
    //     ans.push(head->data);
    //     while (temp->next != NULL)
    //     {
    //         temp = temp->next;
    //         if (ans.head->data != temp->data)
    //         {
    //             ans.push(temp->data);
    //         }
    //     }
    //     ans.traverse();
    // }
    // Approach 2: TC: O(n) SP: O(1)

    void removeDuplicates(){
        Node* temp=head;
        while(temp->next!=NULL){
            if(temp->data==temp->next->data){
                if(temp==head){
                    head=head->next;
                    temp=head;
                }else{
                    temp->next=temp->next->next;
                }
            }else{
            temp=temp->next;
            }
        }
    }
    
};

int main()
{
    LinkedList l1;
    l1.push(2);
    l1.push(2);
    l1.push(2);
    l1.push(3);
    l1.push(3);
    l1.push(4);
    l1.push(5);
    l1.push(5);
    l1.push(5);
    l1.push(5);
    l1.removeDuplicates();
    l1.traverse();
    return 0;
}