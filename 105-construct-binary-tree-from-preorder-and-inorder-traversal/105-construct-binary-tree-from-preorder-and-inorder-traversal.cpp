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
    unordered_map<int,int> map;
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& idx, int low, int high,unordered_map<int,int>& map)
    {
        if(low>high)
            return NULL;
        
        TreeNode* root= new TreeNode(preorder[idx]);
        idx++;
        //auto inorderIn=lower_bound(inorder.begin(),inorder.end(),root->val)-inorder.begin();
        /*for(int i=low;i<=high;i++)
        {
            if(inorder[i]==root->val)
            {
                inorderIn=i;
                break;
            }
        }*/
        int value=map[root->val];
        root->left=helper(preorder,inorder,idx,low,value-1,map);
        root->right=helper(preorder,inorder,idx,value+1,high,map);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        TreeNode* root=NULL;
        int idx=0;
        int i=0;
        for(auto it: inorder)
        {
            map[it]=i++;
        }
        
        return helper(preorder,inorder,idx,0,preorder.size()-1,map);
        
        
        
        
    }
};