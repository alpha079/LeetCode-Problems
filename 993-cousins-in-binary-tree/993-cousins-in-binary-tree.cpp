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

//For this Question,
// What I can do if find level of both nodes, and parent of both nodes.
// If LevelX==LevelY and ParentX!=ParentY

void helper(TreeNode* root,int parent,int x,int level,pair<int,int>&p )
{
    if(root==NULL)
        return;
    if(root->val==x)
    {
        p=make_pair(parent,level);
        return;
    }
    helper(root->left,root->val,x,level+1,p);
    helper(root->right,root->val,x,level+1,p);
    
}
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        pair<int,int> p1,p2;
        
        helper(root,-1,x,1,p1);
        helper(root,-1,y,1,p2);
        return p1.first!=p2.first and p1.second==p2.second;
        
    }
};