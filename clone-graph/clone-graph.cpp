/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
//Time: O(M + N) where N is the number of nodes and M is the number of edges.
//Space: O(N)

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr)return NULL;
        
        unordered_map<Node*,Node*>map;
        Node* temp= new Node(node->val);
        map[node]=temp;
        queue<Node*> q;
        
        q.push(node);
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            vector<Node*> list;
            for(auto ngb: it->neighbors)
            {
                if(map.find(ngb)!=map.end())
                {
                    list.push_back(map[ngb]);
                }
                else{
                    temp=new Node(ngb->val);
                    map[ngb]=temp;
                    q.push(ngb);
                    list.push_back(temp);
                    
                }
            }
            map[it]->neighbors=(list);
            
        }
        return map[node];
        
        
        
    }
};
