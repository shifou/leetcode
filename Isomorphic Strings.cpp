class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> h1,h2;
        if(s.size()!=t.size())
            return false;
        for(int i=0;i<s.size();i++)
        {
            if(h1.find(s[i])==h1.end())
            {
                if(h2.find(t[i])==h2.end())
                {
                    h1[s[i]]=t[i];
                    h2[t[i]]=s[i];
                }
                else
                    return false;
            }
            else
            {
                if(h1[s[i]]!=t[i])
                    return false;
            }
        }
        return true;
    }
};