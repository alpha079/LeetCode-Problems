
 /*
 Here next() takes "on average" O(1) time as each node goes into stack once and goes out of stack once.
This is in fact average O(1) time. The while loop is misleading you to think it is not. Think about the number of times a node has been visited after iterating the whole tree. Each node has been visited twice. In some cases the while loop doesn't execute, so that node at that call is only visited once. Where does the other visit go? It goes to the while loop when you visit another node. That's why it's "average" O(1) time.
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