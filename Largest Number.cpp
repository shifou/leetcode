class Solution {
public:
    string trim(string &s)
    {
        int pos=-1;
        for(int i=0;i<s.size();i++)
        if(s[i]!='0')
        {
            pos=i;
            break;
        }
        if(pos==-1)
           return "0";
           else
        return s.substr(pos);
    }
    string largestNumber(vector<int> &num) {
        vector<string> hold;
        for(int i=0;i<num.size();i++)
          hold.push_back(to_string(num[i]));
         sort(hold.begin(),hold.end(),cmp);
         string ans="";
         for(int i=0;i<hold.size();i++)
           ans+=hold[i];
          return trim(ans);
    }
};