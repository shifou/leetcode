class Solution {
public:
    string countAndSay(int n) {
        string ans="1";
        for(int i=1;i<n;i++)
        {
            string res=ans;
            string hold="";
            for(int j=0;j<res.size();j++)
            {
                int ct=1;
                for(int k=j+1;k<res.size();k++)
                {
                 if(res[k]==res[j]) ct++;
                 else break;
                }
                hold+=(ct+'0');
                hold+=res[j];
                j+=(ct-1);
            }
            ans=hold;
        }
        return ans;
    }
};