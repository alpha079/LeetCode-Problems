

class Solution {
public:
    //Push the linked list into a vector
    //Now construct the tree from that vector
    
    //Time:- O(N)
    //SC:- O(N)
    
    TreeNode* constructTree(vector<int>& ar, int low, int high)
    {
        if(low>high)
        {
            return NULL;
            
        }
        
        int mid=(low+high)/2;
        
        TreeNode* root=new TreeNode(ar[mid]);
        root->left=constructTree(ar,low,mid-1);
        root->right=constructTree(ar,mid+1,high);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        
        if(head==NULL)
            return NULL;
        if(head->next==NULL)
            return new TreeNode(head->val);
        vector<int> ans;
        
        ListNode* node=head;
        while(node)
        {
            ans.push_back(node->val);
            node=node->next;
        }
        
        TreeNode* root= constructTree(ans,0,ans.size()-1);
        return root;
    }
};