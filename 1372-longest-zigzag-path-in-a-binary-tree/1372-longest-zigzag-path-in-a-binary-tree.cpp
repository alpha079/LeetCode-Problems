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
    int ans=0;
    int helper(TreeNode* root,int dir)
    {
        if(root==NULL)
            return 0;
        int leftSubproblem=helper(root->left,-1);
        int rightSubproblem=helper(root->right,1);
        
        if(dir==-1)
        {
            if(rightSubproblem+1>ans)
            {
                ans=rightSubproblem+1;
            }
            return rightSubproblem+1;
        }
        else if(dir==1)
        {
             if(leftSubproblem+1>ans)
            {
                ans=leftSubproblem+1;
            }
            return leftSubproblem+1;
            
        }
        else if(!dir){ //dir will be 0 for root node
            
             if(rightSubproblem>ans)
            {
                ans=rightSubproblem+1;
            }
            if(leftSubproblem>ans)
            {
                ans=leftSubproblem+1;
            }
            return ans;
        }
        return 0;
            
    }
    int longestZigZag(TreeNode* root) {
        
        if(root==NULL)
            return 0;
        
        return helper(root,0);
       
        
    }
};