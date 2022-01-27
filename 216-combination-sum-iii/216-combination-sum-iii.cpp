class Solution {
public:
    
    /*
    Time: O(K * 9^K)
Space: O(K)


Since we have a pool of 9 number to choose from, let's say the pool size is P (in this case P = 9) and each node can have at most P branches (in actual cases, it is in most time less than P). This backtracking can at most have (K + 1) levels. So, time complexity is less than O(K * P^K) (copying K-size list takes O(K)).
*/
    void solve(int k, int n,  vector<vector<int>>& res, vector<int>& temp,int beg)
    {
        if(k==0&& n==0)
        {
            res.push_back(temp);
        }
        for(int i=beg;i<10 && i<=n;++i)
        {
            temp.push_back(i);
            solve(k-1,n-i,res,temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        
         vector<vector<int>> res;
        vector<int> temp;
        
        solve(k,n,res,temp,1);
        return res;
        
        
    }
};