/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& idx, int low, int high)
    {
        if(low>high)
            return NULL;
        
        TreeNode* root= new TreeNode(preorder[idx]);
        idx++;
        int inorderIn=0;
        for(int i=low;i<=high;i++)
        {
            if(inorder[i]==root->val)
            {
                inorderIn=i;
                break;
            }
        }
        root->left=helper(preorder,inorder,idx,low,inorderIn-1);
        root->right=helper(preorder,inorder,idx,inorderIn+1,high);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        TreeNode* root=NULL;
        int idx=0;
        
        return helper(preorder,inorder,idx,0,preorder.size()-1);
        
        
        
        
    }
};