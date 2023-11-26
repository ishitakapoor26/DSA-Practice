/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    int lengthLL(ListNode* head){
        int count=0;
        ListNode* temp=head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }
    
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL ||head->next==NULL) return head;
        int length= lengthLL(head);
        k=k%length;
        if(k==0) return head;
        ListNode* temp1=head;
        for(int i=0;i<length-k-1;i++){
            temp1=temp1->next;
        }
        ListNode* temp2=temp1->next;
        temp1->next=NULL;
        ListNode* temp3= temp2;
        while(temp3->next!=NULL){
            temp3=temp3->next;
        }
        temp3->next=head;
        head=temp2;
        return head;
    }
};