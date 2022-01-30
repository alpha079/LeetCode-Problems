
//Coutn the length of the linked List
//Check, if k is overflowing or not. if overflowing, make it in range
//Make Last node of LInked List points to head. (make it circular)
//Then traverse the curr(which is at end now), by n-k moves.
//Update head and curr->next to NULL
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head==NULL or k==0)
            return head;
        
        ListNode* curr=head;
        int cnt=1;
        while(curr->next!=NULL)
        {
            curr=curr->next;
            cnt++;
        }
        curr->next=head;
        k=k%cnt;
        
       k=cnt-k;
        while(k--)
        {
            curr=curr->next;
        }
        head=curr->next;
        curr->next=NULL;
        return head;
    }
};