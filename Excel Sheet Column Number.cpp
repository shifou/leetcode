class Solution {
public:
    int titleToNumber(string s) {
        int ans=0;
        int hold=1;
        for(int i=s.size()-1;i>=0;i--)
        {
            ans+=(s[i]-'A'+1)*hold;
            hold*=26;
            
        }
        return ans;
    }
};