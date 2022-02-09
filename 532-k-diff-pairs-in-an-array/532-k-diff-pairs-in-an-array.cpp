class Solution {
public:
    
    //Using Binary Search
    //TC:- O(NlogN)
    
    bool BinarySearch(vector<int>& ar, int low, int high, int target)
    {
        int mid;
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(ar[mid]==target)
                return true;
            else if(ar[mid]>target)
                 high=mid-1;
            else low=mid+1;
        }
        return false;
    }
    int findPairs(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        
        int ans=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(i>0 && nums[i]==nums[i-1])
                continue;
            if(BinarySearch(nums,i+1,nums.size()-1,k+nums[i]))
                 ans++;
            
        }
        return ans;
        
    }
};