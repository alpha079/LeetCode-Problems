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
//if inorder traversal is 1,2,3,4,5,6,7,8 and we swap 7 and 4 , we get
// 1 2 3 7 5 6 4 8 9, here 7>5 and 6>4
//so vector<pair<TreeNode*,TreeNode*>> will have two value
//[7,5] [6,4] then swap 7 and 4 from pair
class Solution {
public:
    
    //TC:- O(N)
    //SC:- O(2)== O(1)
    vector<pair<TreeNode*,TreeNode*>> pair;
    TreeNode* prev=NULL;
    void inorder(TreeNode* root)
    {
        if(!root)
            return;
        inorder(root->left);
        if(prev and prev->val>root->val)
        {
            pair.push_back({prev,root});
        }
        prev=root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        if(pair.size()==1)
        {
            swap(pair[0].first->val,pair[0].second->val);
        }
         if(pair.size()==2)
        {
            swap(pair[0].first->val,pair[1].second->val);
        }
        
    }
};