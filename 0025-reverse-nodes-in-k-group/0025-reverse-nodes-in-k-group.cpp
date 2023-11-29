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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || k==1) return head;
        int count=0;
        ListNode* dummy= new ListNode();
        dummy->next=head;
        ListNode* pre= dummy;
        ListNode* curr= dummy;
        ListNode* nxt= dummy;
        ListNode* temp=head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        while(count>=k){
            curr=pre->next;
            nxt= curr->next;
            for(int i=1;i<k;i++){
                curr->next=nxt->next;
                nxt->next=pre->next;
                pre->next=nxt;
                nxt=curr->next;
            }
            pre=curr;
            count-=k;
        }
        return dummy->next;
    }
};