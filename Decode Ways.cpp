class Solution {
public:
     int test(string &s)
     {
         int hold=(s[0]-'0')*10+s[1]-'0';
         if(hold>=1&& hold<=26)
            return 1;
        else
           return 0;
     }
    int numDecodings(string s) {
        int n=s.size();
        if(s=="") return 0;
        vector<int> dp;
        dp.resize(n);
       if(s[0]=='0')
          return 0;
        else 
          dp[0]=1;
          if(s.size()>=2)
          {
              string hh=s.substr(0,2);
            if(s[1]=='0')
            {
              if(test(hh))
                 dp[1]=1;
              else
                 return 0;
            }
            else
            {
                if(test(hh))
                    dp[1]=2;
                else
                  dp[1]=1;
            }
          }
         for(int i=2;i<s.size();i++)
         {
             string hh=s.substr(i-1,2);
            if(s[i]=='0')
            {
                if(test(hh))
                 dp[i]=dp[i-2];
              else
                 return 0;
            }
            else
            {
              if(s[i-1]!='0'&&test(hh))
                 dp[i]=dp[i-2]+dp[i-1];
            else
                  dp[i]=dp[i-1];
            }
         }
        return dp[s.size()-1];
    }
};