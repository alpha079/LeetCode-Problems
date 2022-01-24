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
    bool isCousins(TreeNode* root, int x, int y) {
        if(root==NULL)
            return false;
        
    queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            bool foundX=false;
            bool foundY=false;
            int size=q.size();
            
            while(size--)
            {
                TreeNode* curr=q.front();
                q.pop();
                
                if(curr->val==x)
                    foundX=true;
                 if(curr->val==y)
                    foundY=true;
                
                if(curr->left and curr->right)
                {
                    if((curr->left->val==x and curr->right->val==y) || (curr->left->val==y and curr->right->val==x))
                    {
                        return false;
                        //beacuse x and y belong to same parent
                    }
                }
                
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
                
                
                
                
            }
            if(foundX==true and foundY==true)
                return true;
            else false;
        }
        return false;
        
    }
};