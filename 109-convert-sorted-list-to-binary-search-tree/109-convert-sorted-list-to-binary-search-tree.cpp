

//Find Mid of linked list and make mid as root.
//Then recursively call like this
//Just like the merge porcess of Merge Sort
class Solution {
public:
    //TC:- O(nlogn)
    //SC:- O(logn)
    TreeNode* sortedListToBST(ListNode* head) {
        
        if(head==NULL)
            return NULL;
        if(head->next==NULL)
            return new TreeNode(head->val);
        
        ListNode* slow=head,*fast=head,*mid=NULL;
        
        while(fast and fast->next)
        {
            mid=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        mid->next=NULL;
        
        TreeNode* root=new TreeNode(slow->val);
        root->left=sortedListToBST(head);
        root->right=sortedListToBST(slow->next);
        
        return root;
    }
};