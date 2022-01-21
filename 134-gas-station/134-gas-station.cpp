//Case 1: if sum of gasStation is smaller  than the costSum, then we cannot travel back to starting index. So return -1.
//case 2:- If at any index, we find currSum to be negative , then we cannot start from that index


//Tc: O(N)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int gasSum=0;
        int costSum=0;
        
        for(auto it: gas)
        {
            gasSum+=it;
        }
        for(auto it: cost)
        {
            costSum+=it;
        }
        if(gasSum<costSum)
            return -1;
        int start=0;
        int currSum=0;
        for(int i=0;i<gas.size();i++)
        {
            currSum+= (gas[i]-cost[i]);
            if(currSum<0)
            {
                start=i+1;
                currSum=0;
            }
        }
        return start;
        
    }
};