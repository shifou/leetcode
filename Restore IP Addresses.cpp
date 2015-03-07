class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        fk(ans, 0,0, "",s);
        return ans;
    }
    void fk(vector<string> & a, int dp,int pos,  string now, string ori)
    {
        if(dp==4 && pos==ori.size())
        {
            a.push_back(now);
            return;
        }
        if(dp==4)
            return;
             if(dp!=0)
                now.push_back('.');
        int hold=0;
        for(int i=pos;i<ori.size();i++)
        {
            hold=hold*10+ori[i]-48;
            if(hold>255) break;
            //if(i==0hold!=0&&ori[i]!='0');
            now.push_back(ori[i]);
           // if(ori.size()-pos-1>3*(4-dp-1)) continue;
            fk(a,dp+1,i+1,now,ori);
            if(hold==0) break;
        }
    }
};