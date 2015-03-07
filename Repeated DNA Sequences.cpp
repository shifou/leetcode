class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        if(s.size()<=10)
           return ans;
        unordered_map<int,int> vis;
        int i=0,len=s.size();
        
        int cur=0;
        map<char,int> fk;
        fk['A']=0;
        fk['C']=1;
        fk['G']=2;
        fk['T']=3;
        int mask = (1<<20)-1;
        for(;i<10;i++)
        {
                        cur<<=2;
            cur|=fk[s[i]];
        }
        vis[cur]++;
        for(i=1;i<=len-10;i++)
        {
            cur<<=2;
            cur&=mask;

            cur=(cur|fk[s[i+9]]);
            vis[cur]++;
            if(vis.find(cur)!=vis.end())
            {
                if(vis[cur]==2)
                ans.push_back(s.substr(i,10));
            }
            else
               vis[cur]=1;
        }
        return ans;
    }
};