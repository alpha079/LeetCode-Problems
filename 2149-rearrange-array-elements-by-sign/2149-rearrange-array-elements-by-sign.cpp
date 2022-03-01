class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        
        int idxpos=0,idxneg=1;
        vector<int> res(nums.size(),0);
        for(auto it: nums)
        {
            if(it>0)
            {
                res[idxpos++]=it;
                 idxpos++;
                
            }
            else{
                res[idxneg]=it;
                idxneg+=2;
            }
        }
        return res;
        
    }
};