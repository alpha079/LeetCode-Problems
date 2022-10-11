class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(size(nums)==1 || size(nums)==2){
            return false;
        }
        int x=INT_MAX,y=INT_MAX;
        for(int a=0;a<size(nums);a++){
            if(y<nums[a]) return true;
            else if(nums[a]<y && nums[a]>x){
                y=nums[a];
            }else if(nums[a]<x){
                x=nums[a];
            }
        }
        return false;
    }
};