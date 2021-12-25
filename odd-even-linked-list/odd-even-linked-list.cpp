
//This is O(N) appraoch with Space O(N).
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL)return NULL;
        vector<ListNode*> odd, even;
        
        bool oddV=true;
        while(head)
        {
            if(oddV)
            {
                odd.push_back(head);
            }
            else{
                even.push_back(head);
            }
            oddV=!oddV;
            head=head->next;
        }
        head=odd[0];
        ListNode* curr=head;
        for(int i=1;i<odd.size();i++)
        {
            curr->next=odd[i];
            curr=curr->next;
        }
        for(int i=0;i<even.size();i++)
        {
            curr->next=even[i];
            curr=curr->next;
        }
        curr->next=NULL;
        return head;
        
    }
};