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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* fast=head;
        ListNode* slow=head;
        int ptr=k;
        
        while(ptr>1)
        {
            fast=fast->next;
            ptr--;
        }
        ListNode* ff=fast;
        fast=fast->next;
        
        while(fast!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }
        swap(ff->val,slow->val);
        return head;
        
    }
};