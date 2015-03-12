class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> >  ans;
        if(num.size()<=3)
          return ans;
          sort(num.begin(),num.end());
          int n=num.size();
          unordered_map<int,vector<pair<int,int> > > fk;
            fk.reserve(n*n);
            for(int i=0;i<n-1;i++)
               for(int j=i+1;j<n;j++)
                   fk[num[i]+num[j]].push_back(make_pair(i,j));
            vector<int> hold;
            for(int i=0;i<n-3;i++)
            {
                if(i&&num[i]==num[i-1]) continue;
                for(int j=i+1;j<n-2;j++)
                {
                    if(j!=i+1&&num[j]==num[j-1]) continue;
                    if(fk.find(target-num[i]-num[j])!=fk.end())
                    {
                         vector<pair<int,int> > p1 = fk[target-num[i]-num[j]];
                         int st=0;
                         while(st<p1.size() && p1[st].first<=j) {st++;}
                         for(int k=st;k<p1.size();k++)
                         {
                             // 0 0 0 0 0 target 0
                            if(k!=st&&num[p1[k].first]==num[p1[k-1].first]) continue;
                            ans.push_back(vector<int>{num[i], num[j], num[p1[k].first], num[p1[k].second]});
                         }
                    }
                }
            }
        return ans;
    }
};