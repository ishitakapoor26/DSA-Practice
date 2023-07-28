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
    void deleteNode(ListNode* node) {
        ListNode* temp= new ListNode;
        temp=node->next;
        ListNode* ptr= new ListNode;
        ptr=node;
        while(temp->next!=NULL){
            ptr->val=temp->val;
            ptr=temp;
            temp=temp->next;
        }
        ptr->val=temp->val;
        ptr->next=NULL;
    }
};