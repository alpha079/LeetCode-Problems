//Approach
//1: We have to count the Zeroes from PreZero, MidZero, SufZero
//PreZero -> means we have not discivered any 1 yet
//midZero -> means we have discovered 1 and iterating to discover another one
//SufZero -> We have discovered two 1, and now discovering after it

// We have three option to place the person
/*
There are 3 cases:

Beginning : Alice sits in 0 position (if free), here distance is next person position.
Eg: 0 0 0 1 0 0 => A 0 0 0 1 0 0 => dis = 4
Mid of two ppl : Alice sits between two people. Find distance is half of the distance between those two people.
Eg: 0 1 0 0 0 1 0 => 0 1 0 A 0 1 0 => dis = 2
3.At the End : Alice sits in n-1 position (if free), here distance is difference between n-1 and last person position.
Eg: 0 1 0 0 0=> 0 1 0 0 A=> dis = 3

*/

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        
    int zero=0,preZero=-1,midZero=0,sufZero=0;
        
        for(auto it: seats)
        {
            if(it==0)
                zero++;
            else{
                if(preZero==-1)
                {
                    preZero=zero;
                }
                else{
                    midZero=max(midZero,zero);
                }
                zero=0;
            }
            
        }
        sufZero=zero;
         return max(max(sufZero,preZero), (midZero+1)/2);
        
    }
   
};