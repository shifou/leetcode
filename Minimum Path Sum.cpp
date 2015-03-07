class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > dp(grid.size());
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
                dp[i].push_back(0);
        }
        for(int i=0;i<grid[0].size();i++)
        {
            dp[0][i]=grid[0][i];
            if(i)
                dp[0][i]+=dp[0][i-1];
        }
        for(int i=1;i<grid.size();i++)
        {
            dp[i][0]=grid[i][0];
            dp[i][0]+=dp[i-1][0];
        }
        for(int i=1;i<grid.size();i++)
        {
            for(int j=1;j<grid[i].size();j++)
            {
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }
        return dp[grid.size()-1][grid[grid.size()-1].size()-1];
    }
};