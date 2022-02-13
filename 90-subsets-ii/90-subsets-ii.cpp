class Solution {
public:
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        unordered_set<string> hash;
        int size=(1<<n);
        
        for(int mask=0;mask<size;mask++)////O(2^N)
        {
            vector<int> sub;
            string temp="";
            for(int i=0;i<nums.size();i++)  //O(N)
            {
                if((mask & (1<<i))!=0)
                {
                    sub.push_back(nums[i]);
                    temp+=to_string(nums[i])+ ",";
                }
            }
            if(!hash.count(temp))
            {
                ans.push_back(sub);
                hash.insert(temp);
            }
        }
        return ans;
    }
};