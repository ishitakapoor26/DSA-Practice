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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL){
            return nullptr;
        }
        else if(head->next==NULL){
            return head;
        }
        ListNode* p= NULL;
        ListNode* t= head;
        ListNode* n= head->next;
        while(t->next!=NULL){
            t->next=p;
            p=t;
            t=n;
            n=n->next;
        }
        t->next=p;
        return t;
    }
};