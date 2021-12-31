//Time:-O(V+E)
//Kahn's Algorithm is used for Topological Sort
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
   
        
        vector<int> List[numCourses];
        vector<int> indegree(numCourses);
        for(int i=0;i<prerequisites.size();i++)
        {
            List[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        vector<int> result;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            
            for(auto ngh: List[node])
            {
                indegree[ngh]--;
                if(indegree[ngh]==0)
                    q.push(ngh);
            }
            result.emplace_back(node);
        }
        if(result.size()==numCourses)
            return result;
        return {};
        

        
    }
};