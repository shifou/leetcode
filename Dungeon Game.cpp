class Solution {
public:
// 0 5
// -2 -3
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
    int n=dungeon.size(),m=dungeon[0].size();
    memset(dp,0,sizeof(dp));
    if(dungeon[n-1][m-1]>=0)
    dp[n-1][m-1]=0;
    else
      dp[n-1][m-1]=-dungeon[n-1][m-1];
    for(int i=m-2;i>=0;i--)
    {
      if(dungeon[n-1][i]>=0) dp[n-1][i]=max(0,dp[n-1][i+1]-dungeon[n-1][i]);
      else dp[n-1][i]= -dungeon[n-1][i]+dp[n-1][i+1];

    }
    for(int i=n-2;i>=0;i--)
    {
             if(dungeon[i][m-1]>=0) dp[i][m-1]=max(0,dp[i+1][m-1]-dungeon[i][m-1]);
      else dp[i][m-1]= -dungeon[i][m-1]+dp[i+1][m-1];
    }
    for(int i=m-2;i>=0;i--)
    {
        for(int j=n-2;j>=0;j--)
        {
            int hold;
            if(dungeon[j][i]>=0) dp[j][i]=max(0,min(dp[j+1][i],dp[j][i+1])-dungeon[j][i]);
            else dp[j][i]= -dungeon[j][i]+min(dp[j+1][i],dp[j][i+1]);
         }
    }
    return dp[0][0]+1;
    }
};