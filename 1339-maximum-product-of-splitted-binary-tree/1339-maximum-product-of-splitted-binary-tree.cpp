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
    int GetTotal(TreeNode* root)
    {
        int sum= root->val + (root->left?GetTotal(root->left):0) +(root->right?GetTotal(root->right):0);
        return sum;
    }
    
    int getProduct(TreeNode* root,long long &res,long long total)
    {
        long temp=root->val;
        temp+=(root->left ?getProduct(root->left,res,total):0);
        
        temp+=(root->right ?getProduct(root->right,res,total):0);
        
        res=max(res,(total-temp)*temp);
        
        return temp;
    }
    int maxProduct(TreeNode* root) {
        
        if(root==NULL)
            return 0;
        
        long long getTotal=GetTotal(root);
        long long res=0;
        getProduct(root,res,getTotal);
        return res%1000000007;
        
        
    }
};