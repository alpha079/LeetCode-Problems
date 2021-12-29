class Solution {
public:
    
    //Why do Mulitply, Just we  have to see the value,
    // If it is positive or negatice or Zero
    int arraySign(vector<int>& nums) {
        int product = 1;
        for(auto num : nums) {
            if(num < 0) product = -product;
            else if(num == 0) return 0;
        }
        return product > 0 ? 1 : -1;
    }
};