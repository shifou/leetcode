class Solution {
public:
// AAC
    string convertToTitle(int n) {
        string ans="";
        int hold=26;
        while(n)
        {
            int r=(n-1)%hold;
          
             ans+=('A'+r);
            n=(n-1)/26;
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};