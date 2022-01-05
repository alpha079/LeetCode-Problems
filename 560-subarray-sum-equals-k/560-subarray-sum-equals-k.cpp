class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefixSum=0;
        
        unordered_map<int,int> map;
        map[prefixSum]=1;   //[0,1] This is important
        int res=0;
        for(auto it: nums)
        {
            prefixSum+=it;
            
            if(map.find(prefixSum-k)!=map.end())
            {
                res+=map[prefixSum-k];
            }
            
            map[prefixSum]++; //This Step will handle below both steps
            /*
            if(mp.find(prefixSum)!=mp.end())
				mp[prefixSum] = mp[prefixSum] + 1;

			//is prefixSum not present in hashMap then give count = 1
			else
				mp[prefixSum] = 1;
                */
        }
        return res;
        
    }
};