/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return nullptr;
        Node* iter= head;
        while(iter!=NULL){
            Node* temp= new Node(iter->val);
            temp->next=iter->next;
            iter->next=temp;
            iter=iter->next->next;
        }
        iter=head;
        while(iter!=NULL){
            if(iter->random!=NULL)
                iter->next->random= iter->random->next;
            iter= iter->next->next;
        }
        iter=head;
        Node* ptr= iter->next;
        Node* dummy= iter->next;
        while(iter!=NULL && ptr!=NULL){
            iter->next=ptr->next;
            if(ptr->next!=NULL)
                ptr->next=ptr->next->next;
            iter=iter->next;
            ptr=ptr->next;
        }
        return dummy;
    }
};