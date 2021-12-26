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
        
        int cnt=0;
        
        ListNode* curr=head;
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        
        
        while(curr!=NULL)
        {
            cnt++;
            curr=curr->next;
        }
        curr=head;
        ListNode* prev=dummy;
        ListNode *nxt=head;
        while(cnt>=k)
        {
            curr=prev->next;
            nxt=curr->next;
            
            
            for(int i=1;i<k;i++)
            {
                curr->next=nxt->next;
                nxt->next=prev->next;
                prev->next=nxt;
                nxt=curr->next;
            }
            prev=curr;
            cnt-=k;
        }
        
        return dummy->next;
        
    }
};