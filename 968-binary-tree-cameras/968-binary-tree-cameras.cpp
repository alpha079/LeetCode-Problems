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
    int cnt=0;
    
    string CountCamera(TreeNode* root)
    {
        if(root==NULL)
            return"ok";
        string left=CountCamera(root->left);
        string right=CountCamera(root->right);
        
        if(left=="want" || right=="want")
        {
            cnt++;
            return "provide";
        }
        else if(left=="provide" || right=="provide")
        {
            return "ok";
        }
        else return "want";
    }
    int minCameraCover(TreeNode* root) {
       
        if(CountCamera(root)=="want")
        {
            cnt++;
        }
        
        return cnt;
        
    }
};