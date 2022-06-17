class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        
        
        int res=0, remBottle=0;
        
        while(numBottles>0)
        {
            res+=numBottles;
            numBottles+=remBottle;
            remBottle=numBottles%numExchange;
            numBottles/=numExchange;
            
        }
        return res;
    }
};