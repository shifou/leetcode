class Solution {
public:
    int rob(vector<int> &num) {
        int ans=0;
        if(num.size()==0)
            return 0;
        vector<int> dp(num.size(),0);
        dp[0]=num[0];
        if(num.size()>=2)
            dp[1]=max(dp[0],num[1]);
        for(int i=2;i<num.size();i++)
        {
            dp[i]=max(dp[i-1],dp[i-2]+num[i]);
        }
        return dp[num.size()-1];
    }
};