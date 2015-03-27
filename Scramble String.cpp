int dp[102][102][102];
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1==s2)
           return true;
        if(s1.size()!=s2.size())
           return false;
        int n=s1.size();
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                dp[1][i][j]= s1[i]==s2[j];
        for(int k=2;k<=n;k++)
        {
            for(int i=0;i<=n-k;i++)
            {
                for(int j=0;j<=n-k;j++)
                {
                    for(int sp =1;sp<k;sp++)
                    {
                        dp[k][i][j]|= ((dp[sp][i][j] && dp[k-sp][i+sp][j+sp]) || (dp[sp][i][j+k-sp] && dp[k-sp][i+sp][j]));
                    }
                }
            }
        }
        return dp[n][0][0];
    }
};