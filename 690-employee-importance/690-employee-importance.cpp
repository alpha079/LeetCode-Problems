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
    int getImportance(vector<Employee*> employees, int id) {
        int result=0;
        
        for(auto emp: employees)
        {
            if(emp->id==id)
            {
                result+=emp->importance;
                
                if(!emp->subordinates.empty())
                {
                    for(auto it: emp->subordinates)
                  {
                    result+=getImportance(employees,it);
                  }
                    
                }
                return result;
                
            }
            
        }
        return result;
        
    }
};