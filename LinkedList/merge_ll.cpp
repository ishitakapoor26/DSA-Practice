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
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
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
            Node* temp= this->head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=node1;
            node1->next=NULL;
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
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    void merge_list(LinkedList l2, LinkedList l3){
        Node* head1= this->head;
        Node* head2= l2.head;
        Node* head3= l3.head;
        while(head1!=NULL && head2!=NULL){
            if(head1->data<=head2->data){
                l3.push(head1->data);
                head1=head1->next;
            }else{
                l3.push(head2->data);
                head2=head2->next;
            }
        }
        while(head1!=NULL){
            l3.push(head1->data);
            head1=head1->next;
        }
        while(head2!=NULL){
            l3.push(head2->data);
            head2=head2->next;
        }
        l3.traverse();
    }
};

int main(){
    LinkedList l1,l2,l3;
    l1.push(10);
    l1.push(40);
    l1.push(80);
    l2.push(20);
    l2.push(30);
    l2.push(100);
    l2.push(110);
    l1.merge_list(l2,l3);
    return 0;
}

 // if list1 happen to be NULL
		// we will simply return list2.
    //     if(list1 == NULL)
    //         return list2;
		
	// 	// if list2 happen to be NULL
	// 	// we will simply return list1.
    //     if(list2 == NULL)
    //         return list1;
        
    //     ListNode * ptr = list1;
    //     if(list1 -> val > list2 -> val)
    //     {
    //         ptr = list2;
    //         list2 = list2 -> next;
    //     }
    //     else
    //     {
    //         list1 = list1 -> next;
    //     }
    //     ListNode *curr = ptr;
        
	// 	// till one of the list doesn't reaches NULL
    //     while(list1 &&  list2)
    //     {
    //         if(list1 -> val < list2 -> val){
    //             curr->next = list1;
    //             list1 = list1 -> next;
    //         }
    //         else{
    //             curr->next = list2;
    //             list2 = list2 -> next;
    //         }
    //         curr = curr -> next;
                
    //     }
		
	// 	// adding remaining elements of bigger list.
    //     if(!list1)
    //         curr -> next = list2;
    //     else
    //         curr -> next = list1;
            
    //     return ptr;
       
    // }