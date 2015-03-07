class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size())
           return false;
        if(s1=="" && s2==s3)
           return true;
        if(s2=="" &&s1==s3)
           return true;
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        int n=s1.size(),m=s2.size();
        for(int i=1;i<=m;i++)
        {
           if(s3[i-1]==s2[i-1]&&dp[i-1])
              dp[i]=1;
              else
               break;
        }
        for(int i=1;i<=n;i++)
        {
            memset(dp1,0,sizeof(dp1));
            dp1[0] = (s1[i-1]==s3[i-1] && dp[0]);
            for(int j=1;j<=m;j++)
            {
                // 11 -> 01 10
                dp1[j]= (dp[j] && s1[i-1]==s3[i+j-1]) || (dp1[j-1] && s2[j-1]==s3[i+j-1]);
            }
            memcpy(dp,dp1,sizeof(int)*(m+1));
        }
        return dp[m];
    }
};