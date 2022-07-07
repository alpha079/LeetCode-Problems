class Solution {
public:
    
    //DP solution
    int lengthOfLIS(vector<int>& nums) {
        
        int n=nums.size();
        if(n==0)return 0;
        vector<int> res;
        res.push_back(nums[0]);
        for(int i=1;i<n;i++)
        {
            if(nums[i]>res[res.size()-1])
            {
                res.push_back(nums[i]);
            }
            else{
                int x=lower_bound(res.begin(),res.end(),nums[i])-res.begin();
               cout<<x<<endl;
                // We are replacing the element at position, not inserting. 
                // If element is already present at that position , it will be replaced
                res[x]=nums[i];
            }
        }
        
               return res.size();
        
    }

};