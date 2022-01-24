class Solution {
public:
    vector<int> res;
    
    void dfs(int low, int high, int num, int i)
    {
         if(num>=low and num<=high)
        {
            res.push_back(num);
        }
        if(i>9 ||num>high)
            return;
       
        dfs(low,high,num*10+i,i+1);
    }
    vector<int> sequentialDigits(int low, int high) {
        
        for(int i=1;i<=9;i++)
        {
            dfs(low,high,0,i);
        }
        sort(res.begin(),res.end());
        return res;
        
    }
};
