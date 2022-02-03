class Solution {
public:
    //bool ans;
    int checkBalance(TreeNode* root,bool& ans){
        if(!root)
            return 0;
        if(ans==false) // if Answer is already False then return it.
            return 0;
        int leftSubTree = checkBalance(root->left,ans);
        int rightSubTree = checkBalance(root->right,ans);
        if(abs(leftSubTree-rightSubTree) > 1){
            ans = false;
        }
        return 1 + max(leftSubTree, rightSubTree);
    }
    bool isBalanced(TreeNode* root){
        bool ans = true;
        int temp = checkBalance(root,ans);
        return ans;
    }
};