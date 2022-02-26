/*
Understandings:

New node will always be in the right subtree (or will be new root) - since the new element is the last element of the array
Keep traversing in the right subtree till you find a node greater than new node. Keep track of the parent as well. This is the point you need to insert the new node
If you end up all the way right till NULL means this is the smallest element and we just add it to the right subtree
ELSE you have a node in the current tree which is less than your new node. This small node needs to be in the left subtree of the new node as it is part of the left sub-arrary from the new node. Remember new node is the right most element of the array.

*/
class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        
        if(root==NULL)
        {
            return new TreeNode(val);
        }
        if(root->val<val)
        {
            TreeNode *node= new TreeNode(val);
            node->left=root;
            return node;
        }
        root->right=insertIntoMaxTree(root->right,val);
        return root;
        
    }
};