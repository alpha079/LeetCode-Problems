class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int c=1;
        int k=0;
        int prevElem=nums[0];
        for(int i=1;i<nums.size();i++) {
            int currElem = nums[i];
            if(currElem==prevElem&&c>=2) {
                nums[i]=40000;
                k++;
            }
            else if(currElem==prevElem&&c<2){
                c++;
            }
            else if(currElem!=prevElem) {
                prevElem=currElem;
                c=1;
            }   
        }
        sort(nums.begin(),nums.end());
        return nums.size()-k;
    }
};