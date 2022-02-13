class Solution {
public:
    
   
    vector<vector<int>> generate(vector<int>& nums, int size)
    {
        
        int subCnt=(1<<size); //2*size 1 left shift 2
        
        vector<vector<int>> res(subCnt);
        for(int mask=0; mask<subCnt;++mask)
        {
           
            for(int i=0;i<size;++i)
            {
                cout<<i<<" ";
                if((mask &(1<<i))!=0)
                {
                    res[mask].push_back(nums[i]);
                }
            }
            cout<<endl;
            
            
        }
        return res;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
    
        
        return generate(nums,nums.size());
       
        
    }
};