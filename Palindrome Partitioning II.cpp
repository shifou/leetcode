class Solution {
public:
    int minCut(string s) {
        int n=s.size();
        if(s.size()==1||s.size()==0)
          return 0;
          memset(dp,0,sizeof(dp));
          //ans[0]=0;
          memset(ans,0,sizeof(ans));
        for(int i=0;i<n;i++)
        {
           dp[i][i]=1;
            
        }
        for(int i=0;i<n-1;i++)
         {
             if(s[i]==s[i+1])
               dp[i][i+1]=1;
         }
         for(int i=3;i<=n;i++)
         {
             for(int j=0;j<=n-i;j++)
             {
                 int en=j+i-1;
                 if(s[j]==s[en] &&dp[j+1][en-1])
                 {
                     dp[j][en]=1;
                 }
             }
         }
         for(int i=1;i<n;i++)
        {
           if(!dp[0][i])
           {
               ans[i]=ans[i-1]+1;
               for(int j=0;j<i-1;j++) 
                {
                    if(dp[j+1][i])
                      ans[i]=min(ans[i],ans[j]+1);
                }
           }
        }
         return ans[n-1];
    }
};