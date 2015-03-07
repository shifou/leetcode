class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()==0||s.size()==1)
          return s;
          int st=0,len=1,n=s.size();
          memset(dp,0,sizeof(dp));
         for(int i = 0; i<n; i++)
for(int j=0; j<=i; j++){
dp[j][i] = (s[i]==s[j] && (i-j<2 || dp[j+1][i-1]));
if(dp[j][i] && (i-j+1)>len){
len = i-j+1;
st=j;
}
}
        return s.substr(st,len);
    }
};