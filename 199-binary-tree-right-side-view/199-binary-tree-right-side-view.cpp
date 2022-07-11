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
    
    void helper(TreeNode* root,vector<int>& res, int ml)
    {
        if(root==NULL)return;
        
        if(ml==res.size())
        {
            res.push_back(root->val);
            
        }
        else{
            res[ml]=root->val;
        }
        helper(root->left,res,ml+1);
        helper(root->right,res,ml+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        
        if(root==NULL)return {};
        
        vector<int> res;
        int lastLevel=0;
        helper(root,res,lastLevel);
        return res;
    }
};