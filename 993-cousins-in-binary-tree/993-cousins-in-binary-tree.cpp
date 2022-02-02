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
    void helper(TreeNode* root,int x,int y, int parent, int level)
    {
        if(root==NULL)return;
        if(root)
        {
            if(root->val==x)
            {
                depthX=level;
                parentX=parent;
                return;
            }
            if(root->val==y)
            {
                depthY=level;
                parentY=parent;
                return;
            }
        }
        helper(root->left,x, y, root->val,level+1);
        helper(root->right,x, y, root->val,level+1);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        helper(root,x,y,-1,1);
        return (depthX==depthY) and (parentX!=parentY);
        
    }
private:
    int depthX=0,depthY=0;
    int parentX=0,parentY=0;
};