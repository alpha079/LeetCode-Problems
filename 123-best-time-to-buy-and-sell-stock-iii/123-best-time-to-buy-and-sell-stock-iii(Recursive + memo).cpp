//Time Complexity - O(K*N*N), Space Complexity - O(K*3*N) (here k = 2)

class Solution {
public:
    vector<vector<vector<int>>> mem;
    
    int count(vector<int>& ar, int i,int k, bool buy )
    {
        if(i>=ar.size()|| k==0)return 0;
        
        if(mem[buy][k][i]!=-1)
         {
            return mem[buy][k][i];
        }
        mem[buy][k][i]=count(ar,i+1,k,buy); //we have skipped the curent day
        
        if(buy)
        {
            mem[buy][k][i]=max(mem[buy][k][i],count(ar,i+1,k-1,false)+ar[i]);  //SELL
        }
        else{
            mem[buy][k][i]=max(mem[buy][k][i],count(ar,i+1,k,true)-ar[i]);  //BUY
        }
        return mem[buy][k][i]; 
    }
    int maxProfit(vector<int>& prices) {
        mem.resize(2,vector<vector<int>>(3,vector<int>(prices.size(),-1)));
        return count(prices, 0,2,false);
       
    }

};
