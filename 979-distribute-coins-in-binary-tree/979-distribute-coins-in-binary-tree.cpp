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
    
   int helper(TreeNode* root,int& coins)
   {
       if(root==NULL)
           return 0;
       int l=helper(root->left,coins);
       int r=helper(root->right,coins);
       
       coins+=abs(l)+abs(r);
       
       return root->val+l+r-1;
   }
    int distributeCoins(TreeNode* root) {
        
        if(root==NULL)
            return 0;
        int coins=0;
        
        helper(root,coins);
        
        return coins;
        
    }
};