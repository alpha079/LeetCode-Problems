class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int x=text1.size();
    int y=text2.size();
        int dp[x+1][y+1];
    memset(dp,sizeof(dp),0);

    for(int i=0;i<=x;i++)
    {
        for(int j=0;j<=y;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
            else if(text1[i-1]==text2[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
        
        for(int i=0;i<=x;i++)
        {
            for(int j=0;j<=y;j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
    return dp[x][y];
    }
};