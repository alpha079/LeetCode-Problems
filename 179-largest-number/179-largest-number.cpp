class Solution {
public:
    
    //TC:- O(nlogn)
    
    static bool comp(int a, int b)
    {
        string one=to_string(a);
        string two=to_string(b);
        return one+two>two+one;
    }
    string largestNumber(vector<int>& nums) {
        string res="";
        
        sort(nums.begin(),nums.end(),comp);
        for(auto it: nums)
        {
            res+=to_string(it);
        }
        if(res[0]=='0')return "0";
        return res;
        
        
    }
};