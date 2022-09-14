class Solution {
public:
    //TC:- O(Nlogn)
    
     static bool compare(string& a, string& b)
    {
        if(a.size()==b.size())
            return a>b;
        else return a.size()>b.size();
    }
    struct comparator
    {
        bool operator () (string& a, string& b)
        {
            if(a.size() == b.size())
                return a > b;
            else
                return a.size() > b.size();
        }
    };
    
    string kthLargestNumber(vector<string>& nums, int k) {
        
        
        //sort(nums.begin(),nums.end(),compare);
        
        priority_queue<string,vector<string>,comparator> pq;//Min-Heap declaration
        //TC:- O(nlogk)
        for(int i=0;i<nums.size();i++)
        {
            if(i<k)
            {
                pq.push(nums[i]);
            }
            else{
                pq.push(nums[i]);
                pq.pop();
                
            }
        }
        return pq.top();
        
    }
};