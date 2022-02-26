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
    
    void findInorder(TreeNode* root,vector<int>& ans)
    {
        if(root==NULL)
            return;
        findInorder(root->left,ans);
        ans.push_back(root->val);
        findInorder(root->right,ans);
    }
    
    TreeNode* Solve(vector<int>& ar, int low, int high)
    {
        if(low>high)
            return NULL;
        int mid=(low+high)/2;
        TreeNode* root=new TreeNode(ar[mid]);
        root->left=Solve(ar,low,mid-1);
        root->right=Solve(ar,mid+1,high);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        
        findInorder(root,inorder);
        
        TreeNode* newRoot=Solve(inorder,0,inorder.size()-1);
        
        return newRoot;
        
    }
};