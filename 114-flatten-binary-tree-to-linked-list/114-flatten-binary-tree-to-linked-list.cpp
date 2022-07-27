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
    
    TreeNode* moveTree(TreeNode* root)
    {
        if(root==NULL)return NULL;
        if(root->left==NULL && root->right==NULL)
        {
            return root;
        }
        TreeNode* leftNode=moveTree(root->left);
        TreeNode* rightNode=moveTree(root->right);
        
        if(leftNode)
        {
            leftNode->right=root->right;
            root->right=root->left;
            root->left=NULL;
        }
        if(rightNode)
        {
            cout<<rightNode->val<<" ";
            return rightNode;
        }
        else if(leftNode)
        {
            return leftNode;
        }
        else return root;
        
        
    }
    void flatten(TreeNode* root) {
        
     if(root==NULL)
         return;
        
        stack<TreeNode*> s;
        
        s.push(root);
        TreeNode* curr=NULL;
        
        while(!s.empty())
        {
            TreeNode* it=s.top();
            s.pop();
            
            if(curr)
            {
                curr->left=NULL;
                curr->right=it;
            }
            curr=it;
            if(it->right)
                s.push(it->right);
            if(it->left)
                s.push(it->left);
        }
        
    }
};