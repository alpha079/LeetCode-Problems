/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    //using Recursion
    //Tc:- O(N)
    
    unordered_map<int,Employee*> map;
    int dfs(int id)
    {
        Employee* emp=map[id];
         int result=emp->importance;
        for(auto it: emp->subordinates)
        {
            result+=dfs(it);
        }
        return result;
    }
    int getImportance(vector<Employee*> employees, int id) {
        int result=0;
        
         for(auto it: employees)
         {
             map[it->id]=it;
         }
        return dfs(id);
        
        
    }
};