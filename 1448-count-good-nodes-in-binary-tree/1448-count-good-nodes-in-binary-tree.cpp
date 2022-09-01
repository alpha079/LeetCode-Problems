class Solution {
public:
    int ans=0;
    void dfs(TreeNode * root, int maxi){
        if(root){
            if(root->val>=maxi) ans++;
            dfs(root->left, max(maxi, root->val));
            dfs(root->right, max(maxi, root->val));
        }
    }
    int goodNodes(TreeNode* root) {
        dfs(root,INT_MIN);
        return ans;
    }
};