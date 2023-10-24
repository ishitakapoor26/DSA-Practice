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
        ListNode* node= head;
        while(node!=NULL){
            count+=1;
            node=node->next;
        }
        return count;
    }
    
    ListNode* middleNode(ListNode* head) {
        int idx= lengthLL(head)/2;
        ListNode* node=head;
        for(int i=0;i<idx;i++){
            node=node->next;
        }
        return node;
    }
};