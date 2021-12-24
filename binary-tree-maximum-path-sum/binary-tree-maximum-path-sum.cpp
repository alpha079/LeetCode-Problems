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
    
    int _maxPathSum(TreeNode* root, int &max_sum)
    {
        if(!root)return 0;
        
        int left=_maxPathSum(root->left,max_sum);
        int right=_maxPathSum(root->right,max_sum);
        
        //maximum can be eith left or right plus root, or it can be root itself if both left and right are negative
        int curr_sum=max(max(left,right)+root->val,root->val);
        
        int max_curr_sum=max(curr_sum,left+right+root->val);
        
        max_sum=max(max_curr_sum,max_sum);
        return curr_sum;
        
        
    }
    int maxPathSum(TreeNode* root) {
        
        int max_sum=INT_MIN;
        
        _maxPathSum(root,max_sum);
        return max_sum;
        
    }
};