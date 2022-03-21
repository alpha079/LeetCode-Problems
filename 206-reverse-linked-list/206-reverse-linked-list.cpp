class Solution {        
    public:
        
        ListNode* helper(ListNode *pre, ListNode *root){
            if(root == NULL)
                return pre;
            ListNode *t = root->next;
            root->next = pre;
            return helper(root,t);            
        }
    
        ListNode* reverseList(ListNode* root) {
            return helper(NULL, root);
        }
};