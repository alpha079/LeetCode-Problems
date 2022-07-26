/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //Push the path of first node in one vector
    //Push the path of second noe in second vector
    
    bool find(TreeNode* root,vector<TreeNode*>& v1,TreeNode* p)
    {
        if(root==NULL)
            return false;
        v1.push_back(root);
        if(root==p)
            return true;
        if(find(root->left,v1,p) || find(root->right,v1,p))
            return true;
        v1.pop_back();
        return false;
    }
    
    TreeNode* matchingPoint(vector<TreeNode*>& v1,vector<TreeNode*>& v2)
    {
        
        TreeNode* res=NULL;
        
        int n=v1.size();
        int n1=v2.size();
        for(int i=0;i<n &&i< n1;i++)
        {
            if(v1[i]!=v2[i])
                return res;
            
            res=v1[i];
        }
        return res;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
       if(!root|| root==p || root==q)
           return root;
        
        vector<TreeNode*> v1;
        vector<TreeNode*> v2;
        
        bool x=find(root,v1,p);
        bool y=find(root,v2,q);
        
        return matchingPoint(v1,v2);
        
        
        
    }
};