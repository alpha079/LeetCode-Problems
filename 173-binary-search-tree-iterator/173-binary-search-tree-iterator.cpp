//Using Morris Traversal

class BSTIterator {
public:
    TreeNode* curr=NULL;
    BSTIterator(TreeNode* root) {
        curr=root;
    }
    
    int next() {
        int res=0;
        while(curr!=NULL)
        {
            if(curr->left==NULL)
            {
                res=curr->val;
                curr=curr->right;
                break;
            }
            else{
                TreeNode* prev=curr->left;
                while(prev->right && prev->right!=curr)
                {
                    prev=prev->right;
                }
                if(prev->right==NULL)
                {
                    //Make Thread pointing to curr
                    prev->right=curr;
                    curr=curr->left;
                }
                else{
                    //Remove the thread;
                    prev->right=NULL;
                    res=curr->val;
                    curr=curr->right;
                    break;
                }
            }
        }
        return res;
        
    }
    
    bool hasNext() {
        return curr!=NULL;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */