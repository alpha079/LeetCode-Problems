class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //base case
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        int cnt=0;
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        int carry=0,value;
        while(l1!=nullptr || l2!=nullptr)
        {
            int x=0,y=0;
            if(l1)
            {
                x=l1->val;
                l1=l1->next;
            }
            if(l2)
            {
                y=l2->val;
                l2=l2->next;
            }
            
            value=x+y+carry;
            ListNode* curr=new ListNode(value%10);
            carry=value/10;
            
            cnt++;
            temp->next=curr;
            temp=temp->next;
        }
    
        if(carry)
        {
            ListNode* curr=new ListNode(carry%10);
            carry/=10;
            temp->next=curr;
            temp=temp->next;
        }
        cout<<cnt;
        return dummy->next;
        
    }
};