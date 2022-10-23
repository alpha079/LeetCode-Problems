class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        
       // one more appraoch with maths
        int n=nums.size();
        //This appraoch will only with Single duplicate elements
        int totalSum=n*(n+1)/2;
        
          set<int> st;
        int sum=0;
        for(auto it: nums){
            st.insert(it);
            sum+=it;
        }
      
        
        auto setSum=accumulate(st.begin(),st.end(),0);
        
        int repeat=sum-setSum;
        int miss=totalSum-setSum;
        
        return {repeat,miss};
        
    }
};

//Assume test case to be [5,1,2,3,5]
// Now if we sort then the time Complxity will bedome O(nlogn)
//So, we have to fix the elments at correct positions
// So we perfom Cyclic Sort