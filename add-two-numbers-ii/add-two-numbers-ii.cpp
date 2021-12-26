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
    ListNode* reverse(ListNode* l1)
    {
        ListNode* prev=nullptr,*nxt=nullptr;
        ListNode* ptr=l1;
        
        while(ptr)
        {
            nxt=ptr->next;
            ptr->next=prev;
            prev=ptr;
            ptr=nxt;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
         if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        
        ListNode* first=reverse(l1);
        ListNode* second=reverse(l2);
        
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        int carry=0,value;
        while(first!=nullptr || second!=nullptr || carry==1)
        {
            int x=0,y=0;
            if(first)
            {
                x=first->val;
                first=first->next;
            }
            if(second)
            {
                y=second->val;
                second=second->next;
            }
            
            value=x+y+carry;
            ListNode* curr=new ListNode(value%10);
            carry=value/10;
            
            
            temp->next=curr;
            temp=temp->next;
        }
    
        return reverse(dummy->next);
    }
};