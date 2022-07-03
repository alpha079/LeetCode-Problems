class Solution {
public:
    vector<vector<int>> v;
	
    int select(vector<int>&nums, int i, bool inc){
        if(i >= nums.size()) return 0;
        int x = inc;
        if(v[i][x]!=-1) return v[i][x];
        if((nums[i] > nums[i-1] and inc) or (nums[i] < nums[i-1] and !inc))
           return v[i][x] = select(nums,i+1,inc);
         
       if((nums[i] < nums[i-1] and inc) or (nums[i] > nums[i-1] and !inc))
          return v[i][x] = max(1+select(nums,i+1,!inc),select(nums,i+1,inc));
          
        else return v[i][x] = select(nums,i+1,inc);  
    }
    
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<2) return nums.size();
        v.resize(nums.size()+1,vector<int>(2,-1));
        return 1+max(select(nums,1,true), select(nums,1,false));
    }
};