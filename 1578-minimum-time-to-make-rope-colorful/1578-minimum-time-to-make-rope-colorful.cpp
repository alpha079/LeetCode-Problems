class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
       int prev=0;
        int cost=0;
        for(int i=1;i<size(colors);i++)
        {
          
                if(colors[prev]==colors[i])
                {
                    if(neededTime[i]<neededTime[prev])
                    {
                        cost+=neededTime[i];
                    }
                    else{
                        cost+=neededTime[prev];
                        prev=i;
                    }
                }
                else{
                   prev=i;
                }
            }
        
        return cost;
        
    }
};