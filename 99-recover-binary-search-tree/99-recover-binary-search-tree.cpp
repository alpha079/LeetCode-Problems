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
//First insert the element into a vector using inrder traversal
//then use the sort function to sort the vector.
//Then rewrite teh values from the vector
    //TC:- O(NlogN) + O(2N)
    
    void inorder(TreeNode* root,vector<int>& res)
    {
        if(root==NULL)
            return;
        inorder(root->left,res);
        res.push_back(root->val);
        inorder(root->right,res);
    }
    void ChangeValues(TreeNode* root,vector<int>& res, int& index)
    {
        if(root==NULL)
            return;
        ChangeValues(root->left,res,index);
        root->val=res[index++];
        ChangeValues(root->right,res,index);
    }
    
    void recoverTree(TreeNode* root) {
        vector<int> res;
        inorder(root,res);
        sort(res.begin(),res.end());
        int idx=0;
        ChangeValues(root,res,idx);
        
    }
};