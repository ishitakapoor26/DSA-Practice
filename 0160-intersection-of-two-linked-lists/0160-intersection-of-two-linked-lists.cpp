/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    int length(ListNode* head){
        int count=0;
        while(head!=NULL){
            ++count;
            head=head->next;
        }
        return count;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int la= length(headA);
        int lb= length(headB);
        if(la>lb){
            for(int i=0;i<la-lb;i++){
                headA=headA->next;
            }
        }else if(lb>la){
            for(int i=0;i<lb-la;i++){
                headB=headB->next;
            }
        }
        while(headA!=headB){
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};