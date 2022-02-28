class Solution {
public:
    
    void push(int start,int end, vector<string>& res)
    {
        if(start!=end)
        {
            res.push_back(to_string(start) + "->" +to_string(end));
        }
        else{
            res.push_back(to_string(start));
        }
    }
    vector<string> summaryRanges(vector<int>& nums) {
        
    int n=nums.size();
        if(n==0)
            return {};
        int start=nums[0];
        int end=nums[0];
        vector<string> res;
        for(int i=1;i<n;i++)
        {
            if(nums[i]==1+nums[i-1])
            {
                end=nums[i];
            }
            else{
                push(start,end,res);
                start=nums[i];
                end=nums[i];
            }
        }
        push(start,end,res);
        return res;
        
    }
};