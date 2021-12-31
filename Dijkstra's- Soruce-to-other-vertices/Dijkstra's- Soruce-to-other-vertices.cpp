//Dijkstra's ALgor from Src to all other nodes
//https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/practice-problems/algorithm/shortest-path-problem/
 void dijkstra(int src, int n, int m)
 {
 	//Make Directed graph with gievn input
 	//Unordered_map<int,vector<pair<int,int>>> graph;
 	vector<int> dist(n+1,INF);  
 	dist[src]=0;
 	vector<bool> vis(n+1,false);
 	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

 	pq.push({dist[src],1}); // Dist,Src so that node with minimum dist lies on the top

 	while(!pq.empty())
 	{
 		int d=pq.top().first;
 		int node=pq.top().second;

 		if(vis[node])contine;

 		vis[node]=true;

 		for(auto it: graph[node])
 		{
 			int childNode=it.first;
 			int wt=it.second;
 			if(dist[node]+wt<dist[childNode])
 			 {  
 			 	dist[childNode]=dist[node]+wt;
 			 	pq.push({dist[childNode],childNode});

 			 }

 		}
 	}
 	for(int i=2;i<=n;i++)
   {
       cout<<dist[i]<<" ";
   }
   cout<<endl;
   //Time:- O(V+ElogV)
 }
