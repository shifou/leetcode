class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> ans;
        int len=L[0].size();
        int num=L.size();
        if(L.size()==0)
          return ans;
        map<string,int> q;
        for(int i=0;i<L.size();i++)
          q[L[i]]++;
        for(int i=0;i-1+len*num<S.size();i++)
        {
            map<string,int> ex;
            int j=0;
            for(;j<num;j++)
            {
                string hold=S.substr(i+j*len,len);
                if(q.find(hold)!=q.end())
                   ex[hold]++;
                 else
                    break;
                 if(q[hold]<ex[hold])
                    break;
                
            }
            if(j==num)
               ans.push_back(i);
        }
        return ans;
     }
};