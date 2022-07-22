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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode *lesser=new ListNode(-1);  //dummy nodes
        ListNode *greater=new ListNode(-1); //dummy nodes
        ListNode *lessHead=lesser;
        ListNode *greaterHead=greater;
        
        //TC:- O(N)
        //SC:- O(1)
        
        while(head)
        {
            if(head->val<x)
            {
                lesser->next=head;
                lesser=lesser->next;
                
            }
            else{
                greater->next=head;
                greater=greater->next;
            }
            head=head->next;
        }
        greater->next=NULL;
        lesser->next=greaterHead->next;
        return lessHead->next;
        
        
        
    }
};