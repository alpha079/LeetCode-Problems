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
    int getMax(vector<int>& ar, int low, int high)
    {
        int idx=low;
        for(int i=low+1;i<=high;i++)
        {
            if(ar[i]>ar[idx])
            {
                idx=i;
            }
        }
        return idx;
    }
    
    TreeNode* solve(vector<int>& nums,int low, int high)
    {
        if(low>high)
            return NULL;
        int max_ele=getMax(nums,low,high);
        
        TreeNode* root=new TreeNode(nums[max_ele]);
        root->left=solve(nums,low,max_ele-1);
        root->right=solve(nums,max_ele+1,high);
        
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        
        int n=nums.size();
        
        return solve(nums,0,n-1);
        
    }
};