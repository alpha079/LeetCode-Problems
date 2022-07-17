class Solution {
public:
   /* 
    bool FullyDivide(int ele,vector<int>& numsDivide)
    {
        for(auto it: numsDivide)
        {
            if(it%ele!=0)
                return false;
        }
        return true;
    }
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        
        if(numsDivide.size()==0)
            return 0;
        int ans=0;
        sort(nums.begin(),nums.end());
        
        deque<int> dq;
        for(auto it: nums)
        {
            dq.push_back(it);
        }
        for(int i=0;i<nums.size();i++)
        {
            int ele=dq.front();
            dq.pop_front();
            
            if(FullyDivide(ele,numsDivide)==true)
            {
                return ans;
            }
            ans++;
            
        }
        if(ans==nums.size())
            return -1;
        else return ans;
        
    }
    */
    /*
     "divides all the elements of numsDivide"
equals to
"divides gcd of all the elements of numsDivide"
where gcd is the greatest common divisor.

So the first step, find out the gcd of numsDivide,
then sort input nums A,
and find out the smallest element A[i] in A divides gcd.

We need to remove all elements smaller than A[i].
If no such A[i], return -1


Complexity
Time O(nlogn + m + gcd), where gcd = log(max(numsDivide)
Space O(1)
    */
     int minOperations(vector<int>& nums, vector<int>& num)
     {
         int g=num[0];
         for(auto it: num)
         {
             g=gcd(g,it);
         }
         sort(nums.begin(),nums.end());
         
         int cnt=0;
         for (int i = 0; i < nums.size() && nums[i] <= g; ++i)
            if (g % nums[i] == 0)
                return i;
        return -1;
     }
};
