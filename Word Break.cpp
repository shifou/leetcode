class Solution {
public:
int ans;
ok a[30000];
    void ins(string s)
    {
        int cur=0;
       for(int i=0;i<s.size();i++)
       {
           if(a[cur].next[s[i]-'a'])
           {
               cur=a[cur].next[s[i]-'a'];
           }
           else
           {
               a[cur].next[s[i]-'a']=++ans;
               cur=ans;
            }
       }
       a[cur].end=1;
    }
    void find(string &s, int pos, vector<int> &ans)
    {
        int cur=0;
        for(int i=pos;i<s.size();i++)
        {
            if(a[cur].next[s[i]-'a'])
            {
                if(a[a[cur].next[s[i]-'a']].end) ans[i]=1;
                cur=a[cur].next[s[i]-'a'];
            }
            else
               break;
        }
    }
    bool wordBreak(string s, unordered_set<string> &dict) {
        if(dict.size()==0)
           return false;
        ans=0;
        vector<int> res(s.size(),0);
        for(auto it = dict.begin(); it != dict.end(); it++)
           ins(*it);
         find(s,0,res);
        for(int i=0;i<s.size()&&!res[s.size()-1];i++)
        {
           if(res[i])  
           {
              // printf("%d---\n",i);
               find(s,i+1,res);
           }
        }
        for(int i=0;i<=ans;i++)
        {
            for(int j=0;j<26;j++) a[i].next[j]=0;
            a[i].end=0;
        }
        return res[s.size()-1];
    }
};