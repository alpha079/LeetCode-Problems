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
    
    
    bool helper(TreeNode* root, long lower, long upper)
    {
        if(!root)return true;
        
        if(lower<root->val and root->val<upper)
            return helper(root->left,lower,root->val) and helper(root->right,root->val,upper);
        
        return false;
    }
    bool isValidBST(TreeNode* root) {
        
      return helper(root,LONG_MIN,LONG_MAX);
    }
};