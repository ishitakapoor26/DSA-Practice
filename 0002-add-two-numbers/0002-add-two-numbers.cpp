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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* ptr= new ListNode();
        int temp =(l1->val+l2->val+carry);
        ListNode* curr= new ListNode(temp% 10);
        ptr->next=curr;
        carry= temp/10;
        l1=l1->next;
        l2=l2->next;
        while(l1!=NULL && l2!=NULL){
            temp =(l1->val+l2->val+carry);
            ListNode* newNode= new ListNode(temp%10);
            curr->next= newNode;
            curr=curr->next;
            carry= temp/10;
            l1=l1->next;
            l2=l2->next;
        }
     while(l1!=NULL){
         temp =(l1->val+carry);
            ListNode* newNode= new ListNode(temp%10);
            curr->next= newNode;
            curr=curr->next;
            carry= temp/10;
            l1=l1->next;
     }
        while(l2!=NULL){
         temp =(l2->val+carry);
            ListNode* newNode= new ListNode(temp%10);
            curr->next= newNode;
            curr=curr->next;
            carry= temp/10;
            l2=l2->next;
     }
        if(carry>0){
            ListNode* newHead= new ListNode(carry);
            curr->next=newHead;
        }
        return ptr->next;
    }
};