class Solution {
public:
    
    /* Dijkstra’s Algorithm allows you to calculate the shortest path between 
    one node of your choosing and every other node in a graph. 
    
    Given a graph and a source vertex in the graph, find shortest paths from source
    to all vertices in the given graph.
    
    Time Complexity:  If we take a closer look, we can observe that the statements
    in inner loop are executed O(V+E) times (similar to BFS).
    So overall time complexity is O(E+V)*O(LogV) which is O((E+V)*LogV) = O(ELogV)
    */
	
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        // create adjacency list
        unordered_map<int,vector<pair<int, int>>> adjList;
        for( auto f : flights )
            adjList[f[0]].push_back( { f[1], f[2] } );
        
        // minHeap based on cost of distance from source
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        vector<int> dist(n, INT_MAX); //to avoid TLE 
        minHeap.push({0, src, 0}); // cost, vertex, stops
        
        while(!minHeap.empty()) 
        {
            auto t = minHeap.top(); 
            minHeap.pop();
            int cost = t[0];
            int curr = t[1]; // current Node
            int stop = t[2];
            
            if(curr == dst)
                return cost;
            
             //Optimization to avoid TLE
            if(dist[curr]<stop) continue;
            
            dist[curr]=stop;// mark every node belong to which stop number
            if(stop > k) continue;
            for(auto next : adjList[curr])
                minHeap.push({cost + next.second, next.first, stop+1});
        }
        return -1;
    }
    
};