//Discussion Link:
//https://leetcode.com/problems/palindrome-linked-list/discuss/1137696/Short-and-Easy-w-Explanation-or-T-%3A-O(N)-S-%3A-O(1)-Solution-using-Fast-and-Slow
class Solution {
public:
    //TC:- O(N)
    //SC:- O(1)
    bool isPalindrome(ListNode* head) {
        
        ListNode* slow=head,*fast=head,*prev=NULL,*temp;
        
        while(fast and fast->next)
        {
            fast=fast->next->next;
            temp=slow->next;
            slow->next=prev;
            prev=slow;
            slow=temp;
        }
        //In case of Even Length Linked List, fast will be pointing to NULL;
        //So, in Even Lenght, mid will be at slow position.
        //In case of Odd Length linked list, fast will be pinting to last Node;
        //so , slow will be slow->next
        slow=(fast)?slow->next:slow;
        
        while(slow)
        {
            if(prev->val!=slow->val)
                return false;
            else
            {
                slow=slow->next;
                prev=prev->next;
            }
        }
        return true;
        
    }
};