class Solution {
public:
    bool dfs(vector<int>& num,int k, vector<int>& vis, int idx, int sum, int& target)
    {
        if(k==1)return true;
        if(idx>=num.size())return false;
        if(sum==target)
        {
            return dfs(num,k-1,vis,0,0,target);
            
        }
        for(int i=idx;i<num.size();i++)
        {
            if(vis[i] || sum+num[i]>target)
                continue;
            
             vis[i]=true;
             if(dfs(num,k,vis,i+1,sum+num[i],target))return true;
             vis[i]=false;
            
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int n=nums.size();
        if(n<k)return false;
        int sum=0;
        sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%k)return false;
        
        int target=sum/k;
        
        vector<int> vis(n,false);
        sort(nums.begin(),nums.end(),greater<int>());
        return dfs(nums,k,vis,0,0,target);
        
    }
};