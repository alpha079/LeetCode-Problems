/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        if(root==NULL)return {};
        vector<vector<int>> res;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int size=q.size();
            vector<int> ans;
            while(size>0)
            {
                auto it= q.front();
                q.pop();
                ans.push_back(it->val);
                for(auto el: it->children)
                {
                    q.push(el);
                }
                size--;
            }
            res.push_back(ans);
        }
        return res;
        
    }
};