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
       a[cur].end+=1;
    }
    void find(string &s, int pos, vector<int> &ans)
    {
        int cur=0;
        for(int i=pos;i<s.size();i++)
        {
           // printf("find %c\n",s[i]);
            if(a[cur].next[s[i]-'a'])
            {
                cur=a[cur].next[s[i]-'a'];
                if(a[cur].end) ans[i]=cur;
                
            }
            else
               break;
        }
    }
    void test(string hold, int st,string &s,vector<int> status,vector<string>& ans)
    {
        if(st>=s.size())
         {
             if(status[s.size()-1])
                ans.push_back(hold);
             return;
         }
        vector<int> temp(status);
        find(s,st,temp);
        for(int i=st;i<s.size();i++)
        {
            if(temp[i])
            {
                string k=s.substr(st,i-st+1);
                //cout<<"get str "<<k<<endl;
                status[i]=temp[i];
               // a[temp[i]].end--;
                test(hold+" "+k,i+1,s,status,ans);
                status[i]=0;
               // a[temp[i]].end++;
            }
        }
    }
    bool wordBreak1(string s, unordered_set<string> &dict) {
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
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> fk;
        if(wordBreak1(s,dict)==false)
          return fk;
        ans=0;
        vector<int> res((int)s.size(),0);
        vector<int> init((int)s.size(),0);
        int totalsize=0;
        for(auto it = dict.begin(); it != dict.end(); it++)
        {
            totalsize+=(*it).size();
           ins(*it);
        }
        find(s,0,init);
        for(int i=0;i<s.size();i++)
        {
           if(init[i])  
           {
               //printf("init%d\n",i);
               string k=s.substr(0,i+1);
               //cout<<k<<endl;
               res[i]=init[i];
              // cout<<"node "<<init[i]<<endl;
               //a[init[i]].end--;
                test(k,i+1,s,res,fk);
                res[i]=0;
               // a[init[i]].end++;
              }
        }
        for(int i=0;i<=ans;i++)
        {
            for(int j=0;j<26;j++) a[i].next[j]=0;
            a[i].end=0;
        }
        return fk;
    }
};