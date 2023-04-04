#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
     Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

int size(Node* &head){
    int count=0;
    Node* temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

void insertAtLast(Node *&tail, int num)
{
    Node *temp = new Node(num);
    tail->next = temp;
    temp->next = NULL;
    tail = temp;
}

// void reverseLL(Node* &head){
//     vector<int> reverse;
//     Node* temp=head;
//     while(temp!=NULL){
//         reverse.push_back(temp->data);
//         temp=temp->next;
//     }
//     temp=head;
//     int i=size(head)-1;
//     while(i>=0){
//         if(temp!=NULL){
//             temp->data=reverse[i];
//             temp=temp->next;
//             i--;;
//         }
//     }
// } Approach 1 using array/vector

Node* findAtIndex(Node* &head, int index){
    Node* temp=head;
    for(int i=0;i<index;i++){
        temp=temp->next;
    }
    return temp;
}

// Approach 2
void reverseLL(Node* &head){
    int li=0;
    int ri= size(head)-1;
    while (li<ri)
    {
        int temp= findAtIndex(head,li)->data;
        findAtIndex(head,li)->data=findAtIndex(head,ri)->data;
        findAtIndex(head,ri)->data=temp;
        li++;
        ri--;
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

void InsertAtHead(Node *&head, int d)
{
    if (size(head) == 0)
    {
        head->data = d;
        head->next = NULL;
    }
    else
    {
        Node *temp = new Node(d);
        temp->next = head;
        head = temp;
    }
}


int main(){
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    insertAtLast(tail, 12);
    insertAtLast(tail, 14);
    insertAtLast(tail, 15);
    traverse(head);
    cout<<"Revrsed LL is "<<endl;
    reverseLL(head);
    traverse(head);
    return 0;

}