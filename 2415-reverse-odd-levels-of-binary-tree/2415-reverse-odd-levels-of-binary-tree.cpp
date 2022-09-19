
class Solution {
public:
    
    TreeNode* reverseOddLevels(TreeNode* root) {
        
        if(root==NULL)
            return root;
       queue<TreeNode*> q;
        
        q.push(root);
        int level=0;
        
        vector<int> ele;
        while(!q.empty())
        {
            int size=q.size();
            
            vector<int> temp;
            
           for(int i=0;i<size;i++)
            {
                auto node=q.front();
                q.pop();
                if(level%2!=0)
                {
                    node->val=ele[size-i-1];
                }
              
               if(node->left)
               {
                   q.push(node->left);
                   temp.push_back(node->left->val);
               }
               if(node->right)
               {
                   q.push(node->right);
                   temp.push_back(node->right->val);
               }
                
            }
            ele=temp;
            level++;
        }
        return root;
    }
};