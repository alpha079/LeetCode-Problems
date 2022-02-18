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
    
    void helper(TreeNode* parent,TreeNode* root,int& coins)
    {
        if(root==NULL)
            return;
        helper(root,root->left,coins);
        
        helper(root,root->right,coins);
        
        if(root->val>1)
        {
            int extraCoins=root->val-1;
            
            parent->val+=extraCoins;
            
            coins+=extraCoins;
            
            //root->val=1;
            
        }
        else if(root->val<1)
        {
           int coinNeeded= 1+ abs(root->val); // value can be negative
            
           parent->val-=coinNeeded;
            
            //root->val=1;
            
            coins+=coinNeeded;
        }
    }
    int distributeCoins(TreeNode* root) {
        
        if(root==NULL)
            return 0;
        int coins=0;
        
        helper(root,root,coins);
        
        return coins;
        
    }
};