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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
       /* ListNode* dummy= new ListNode(-1);
        dummy->next=head;
        ListNode* prev=dummy;
        
        for(int i=0;i<left-1;i++)
        {
            prev=prev->next;
        }
        ListNode* curr=prev->next;
        
        for(int i=0;i<right-left;i++)
        {
            ListNode* nxt=curr->next;
            curr->next=nxt->next;
            nxt->next=prev->next;
            prev->next=nxt;
        }
        return dummy->next;
        */
        
        ListNode* curr=NULL;
        int count=0;
        stack<int> s;
        
        curr=head;
        
        while(curr)
        {
            count++;
            if(count>=left and count <=right)
            {
                s.push(curr->val);
            }
            curr=curr->next;
            
        }
        curr=head;
        count=0;
        
        while(curr)
        {
             count++;
            if(count>=left and count <=right)
            {
                curr->val=s.top();
                s.pop();
            }
            curr=curr->next;
            
        }
        return head;
        //TC:- O(N)
        //SC:- O(N) in worst case
        
        
    }
};