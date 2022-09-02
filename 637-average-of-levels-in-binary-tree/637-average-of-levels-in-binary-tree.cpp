class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty())
        {
            double size=q.size(),sum=0;
            for(int i=0;i<size;i++)
            {
                TreeNode * x=q.front();
                sum+=x->val;
                q.pop();
                if(x->left)q.push(x->left);
                if(x->right)q.push(x->right);
            }
            double avg=sum/size;
            ans.push_back(avg);
        }
        return ans;
    }
};