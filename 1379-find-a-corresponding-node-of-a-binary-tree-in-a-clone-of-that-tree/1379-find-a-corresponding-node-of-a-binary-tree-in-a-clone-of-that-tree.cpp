class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(!original or target -> val == original -> val)
            return cloned;
        TreeNode *ptr = getTargetCopy(original -> left, cloned -> left, target);
        if(!ptr) 
            ptr = getTargetCopy(original -> right, cloned -> right, target);
        return ptr;
    }
};