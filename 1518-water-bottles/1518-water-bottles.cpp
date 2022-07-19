class Solution {
public:
    int numWaterBottles(int numBottle, int numExchange) {
        
        
       int res(0), unfilledBottles=0;
        
        //Here numBottles refers to filled bottle left
        
        while(numBottle>0)
        {
            res+=numBottle;
            numBottle+=unfilledBottles;
            unfilledBottles=numBottle%numExchange;
            numBottle/=numExchange;
            
        }
        //tc:- O(log(numBottle))
        return res;
    }
};