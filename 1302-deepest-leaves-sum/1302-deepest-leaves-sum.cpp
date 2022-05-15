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
    int deepestLeavesSum(TreeNode* root) {
        
        if(root==NULL)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int ans=1;
        
        while(!q.empty())
        {
            ans=0;
            int size=q.size();
            
            while(size--)
            {
                auto it= q.front();
                q.pop();
                
                ans+=it->val;
                if(it->left)
                {
                    q.push(it->left);
                }
                if(it->right)
                {
                    q.push(it->right);
                }
            }
            
            
            
        }
        return ans;
    }
};