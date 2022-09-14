class Solution {
public:
    
    int search(int key, vector<int>& res)
    {
        int find=0;
        int low=0,high=res.size()-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            
            if(res[mid]>=key)
            {
                find=mid;
                high=mid-1;
            }
            else{
             low=mid+1;
            }
     
        }
        return find;
    }
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
           /* else{
                int x=lower_bound(res.begin(),res.end(),nums[i])-res.begin();
               cout<<x<<endl;
                // We are replacing the element at position, not inserting. 
                // If element is already present at that position , it will be replaced
                res[x]=nums[i];
            }*/
            else{
                //Think like res array is sorted array, just do Binary Search
                int x=search(nums[i],res);
                res[x]=nums[i];
            }
        }
        
               return res.size();
        //TC:- O(nlogn);
    }

};