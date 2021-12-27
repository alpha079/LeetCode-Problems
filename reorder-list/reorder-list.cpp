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
    ListNode* FindMiddle(ListNode* head)
    {
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(slow && fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* Reverse(ListNode* head)
    {
        ListNode* prev=NULL;
        ListNode* curr=head;
        
        while(curr)
        {
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
            
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next)
            return;
        auto mid=FindMiddle(head);
        ListNode *Right=Reverse(mid);
        ListNode* Left=head->next;
        
        for(int i=0;Left!=Right;i++,head=head->next)
        {
            if(i & 1)
            {
                head->next=Left;
                Left=Left->next;
            }
            else{
                head->next=Right;
                Right=Right->next;
            }
        }
        
        
        
    }
};