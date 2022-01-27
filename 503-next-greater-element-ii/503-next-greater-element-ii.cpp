class Solution {
public:
    //TC:- O(2*N)
    //First I will Enter all the element into the Stack starting from end.
    //Then i will Perform ALgo Just like Nect Greater Element
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res;
        
        stack<int> s;
        
        for(int i=nums.size()-1;i>=0;i--)
        {
            s.push(nums[i]);
        }
        // Now I will pick each element from end of input array, and check if there is element 
        //greater than the current value in the stack
        
       
        for(int i=nums.size()-1;i>=0;i--)
        {
            
            while(!s.empty() and nums[i]>=s.top())
            {
                s.pop();
            }
            if(s.empty())
            {
                res.push_back(-1);
            }
            else{
               res.push_back(s.top());
            }
            s.push(nums[i]);
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};