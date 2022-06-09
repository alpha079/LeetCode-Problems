class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
       vector<int> res;
        int low=0;
        int high=numbers.size()-1;
        
        while(low<=high)
        {
            if(numbers[low]+numbers[high]==target)
            {
                res.push_back(low+1);
                res.push_back(high+1);
                return res;
            }
            else if(numbers[low]+numbers[high]<target)
            {
                low++;
            }
            else high--;
        }
        return res;
    }
};