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
class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        //This Constrcutor will pre-insert the left element only in the stack
        preCompute(root);
        
    }
    void preCompute(TreeNode* root)
    {
        TreeNode* curr=root;
        while(curr!=NULL)
        {
            st.push(curr);
            curr=curr->left;
        }
    }
    
    int next() {
        
        //Return the top node and then insert the Right, and their left Child;
        
        TreeNode* top=st.top();
        st.pop();
        preCompute(top->right);
        return top->val;
        
    }
    
    bool hasNext() {
        return !st.empty();
        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */