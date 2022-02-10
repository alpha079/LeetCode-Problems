//Case 1: if sum of gasStation is smaller  than the costSum, then we cannot travel back to starting index. So return -1.
//case 2:- If at any index, we find currSum to be negative , then we cannot start from that index


//Tc: O(N)

//One pass Code 
//https://leetcode.com/problems/gas-station/discuss/1705957/Java-A-very-detailed-explanation-or-Intuition-behind-logic-or-Brute-Force-to-Optimised
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
       int sum=0;
        int gasInTank=0;
        int start=0;
        
        for(int i=0;i<gas.size();i++)
        {
            gasInTank+=gas[i]-cost[i];
            sum+=gas[i]-cost[i];
            
            if(gasInTank<0)
            {
                start=i+1;
                gasInTank=0;
            }
        }
        return sum>=0 ?start:-1;
    }
};