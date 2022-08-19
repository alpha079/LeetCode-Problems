class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int,int> C;
        for(int x: nums) C[x]++;
        int a=0,b=0,c=0;
        for(int k=-1000; k<=1001; k++){
            if(C[k]<a+b) return false;
            int s = max(0,C[k]-a-b-c);
            c = C[k]-s-a;
            b = a;
            a = s;
        }
        return true;
    }
};