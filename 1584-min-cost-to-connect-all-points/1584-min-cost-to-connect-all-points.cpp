class Solution {
public:
    
    priority_queue<pair<int,pair<int,int>>, 
                   vector<pair<int,pair<int,int>>>, 
                   greater<pair<int,pair<int,int>>>> min_heap;
    
    int get_distance(vector<vector<int>>& points, int i, int j){
        return abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
    }
    
    int Find(vector<int>& parent, int node){
        if(parent[node] == node)
            return node;
        return parent[node] = Find(parent, parent[node]);
    }
    
    void Union(vector<int>& parent, vector<int>& rank,  
               int node1, int node2,
               int node1_parent, int node2_parent){
        
        if(rank[node1] == rank[node2]){
            
            parent[node2_parent] = node1_parent;
            rank[node1_parent]++;            
        }
        else if(rank[node1_parent] < rank[node2_parent])
            parent[node1_parent] = parent[node2_parent];
        
        else 
            parent[node2_parent] = parent[node1_parent];                     
    }
    
    void get_distances(vector<vector<int>> &points){
        int distance;
        
        for(int node1=0; node1<points.size(); node1++){
            for(int node2=node1+1; node2<points.size(); node2++){
                
                distance = get_distance(points, node1, node2);
                min_heap.push({distance, {node1, node2}});                
            }
        }        
    }
    
    int get_mst_distance(vector<int> &parent, 
                         vector<int> &rank){
        
        int node1, node2, node1_parent, node2_parent, mst_distance = 0, distance;     

        while(!min_heap.empty()){
            
            node1 = min_heap.top().second.first;
            node2 = min_heap.top().second.second;
            distance = min_heap.top().first;
            
            node1_parent = Find(parent, node1),  
            node2_parent = Find(parent, node2);
            
            if(node1_parent != node2_parent){
                Union(parent, rank, node1, node2, node1_parent, node2_parent);
                mst_distance += distance;
            }
            min_heap.pop();
        }
        
        return mst_distance;
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {                        
        
        get_distances(points);
        
        vector<int> parent(points.size(),-1), rank(points.size(), 0);        
        
        for(int node=0; node<points.size(); node++) 
            parent[node] = node;                
        
        int min_cost = get_mst_distance(parent, rank);

        return min_cost;        
    }
};