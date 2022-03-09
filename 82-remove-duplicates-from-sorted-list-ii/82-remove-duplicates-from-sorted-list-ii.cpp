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
    ListNode* deleteDuplicates(ListNode* head) {
         if(head==NULL||head->next==NULL)
            return head;
        ListNode* curr=head;
        ListNode* prev=NULL;
        
        
        while(curr!=NULL && curr->next!=NULL)
        {
            if(curr->val==curr->next->val) 
            {
                while(curr->next!=NULL && curr->val==curr->next->val)
                {
                    curr=curr->next;
                }
                if(prev!=NULL)
                {
                    prev->next=curr->next;
                    curr=curr->next;
                    
                }
                else{
                    //if there are duplicates at the starting, chnage the head too.
                    head=curr->next;
                    curr=curr->next;
                }
                
            }
            else{
                //If there are no duplicates, just change the pointers.
                prev=curr;
                curr=curr->next;
            }
        }
        return head;
        
    }
};