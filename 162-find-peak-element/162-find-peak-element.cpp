class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
       //Apply Binary Search/
       // Three cases
        // 1: When mid is at zero index
        // 2: When mid is at nums.size()-1
        // 3: When mid is lying between 0 and nums.size()-1
        
        int low=0,high=nums.size()-1;
        if(low==high)return 0; //only one element is there
        
        while(low<=high)
        {
            int mid= low+ (high-low)/2;
            cout<<mid<<endl;
            
            if(mid>0 and mid<nums.size()-1)
            {
                if(nums[mid]>nums[mid+1] and nums[mid]>nums[mid-1])
                {
                    return mid;
                }
                else if(nums[mid]<nums[mid+1])
                {
                    low=mid+1;
                }
                else high=mid;
            }
            else if(mid==0)  //extreme left condition
            {
                if(nums[mid]>nums[mid+1])
                    return mid;
                else return mid+1;
            }
            else if(mid==nums.size()-1) //extreme right condition 
			{
                cout<<"3"<<endl;
				if(nums[mid]>nums[mid-1])
					return mid;
				else
					return mid-1;
			}
        }
        return -1;
        
    }
};