class Solution {
public:
    string multiply(string num1, string num2) {
        string s;
        if(num2.size()>num1.size())
          swap(num2,num1);
        s=num1+num2;
        for(int i=0;i<s.size();i++) s[i]='0';
        int ct=s.size()-1, add;
       // cout<<num1<<"\t"<<num2<<"\t"<<s<<endl;
        for(int i=num2.size()-1;i>=0;i--)
        {
            int hold=0;
            add=0;
            int be=ct;
            for(int j=num1.size()-1;j>=0;j--)
            {
                hold=(num2[i]-'0')*(num1[j]-'0');
                int left=hold%10;
               
                s[be]=s[be]-'0'+add+left;
                add=s[be]/10+hold/10;
                s[be]=s[be]%10+'0';
               //  cout<<s<<"-----"<<add<<"\t"<<ct<<endl;
                be--;
            }
             if(add) s[be]=add+'0';
            ct--;
        }
       
        int jj=0;
        while(s[jj]=='0') jj++;
        if(jj==s.size()) return string("0");
        else
        return s.substr(jj);
    }
};